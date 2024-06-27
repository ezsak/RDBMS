#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <list>
#include <string>
#include <iterator>
#include <tuple>
#include <map>
#include <cmath>
using namespace std;

class Attr;
class Attr
{

  // base class for attributes
  // add operators for different attribute types in derived classes

public:
  virtual bool operator==(const Attr &right) = 0;
  virtual bool operator!=(const Attr &right) = 0;
  virtual bool operator<(const Attr &right) = 0;
  virtual bool operator<=(const Attr &right) = 0;
  virtual bool operator>(const Attr &right) = 0;
  virtual bool operator>=(const Attr &right) = 0;
};
struct DNFformula
{
  list<list<tuple<string, char, Attr *>>> ops;
};


class Relation;
class Record;
class Record
{

public:
  vector<int> a; // in ordered manner of attributes we store the types
  vector<Attr *> attrptr;
  Record(vector<int> &c)
 ;
  Record(Record &c) ;
  Record &operator=(Record &c)
 ;
  void setattr(vector<Attr *> &v)
 ;

  ~Record()
 ;

  friend class Relation;
  friend Relation *uni(Relation *R1, Relation *R2);
  friend Relation *difference(Relation *R1, Relation *R2);
  friend Relation *cartprod(Relation *R1, Relation *R2);
  friend Relation *projection(Relation *R1, list<string> projectattrs);
  friend Relation *selection(Relation *R1, DNFformula *f);
  friend Relation *rename(Relation *R1, string s1, string s2);
  friend Relation *join(Relation *R1, Relation *R2, list<string> joinattr);
  friend void print(Relation *R);
  friend bool search(Record *lhs, Record *rhs);

  friend class intattr;
  friend class dobattr;
  friend class floattr;
  friend class strattr;
};

class Relation
{

public:
  int nattr, nrecs;         // number of attributes and records
  vector<string> attrnames; // schema
  vector<int> attrinds;     // mapping schema to indices
  list<Record *> recs;      // list of records
  Relation(vector<string> &v, vector<int> &r);

  void addrec(Record *reco)
  ;
  Record *getrecord(int i)
;

  friend Relation *uni(Relation *R1, Relation *R2);
  friend Relation *difference(Relation *R1, Relation *R2);
  friend Relation *cartprod(Relation *R1, Relation *R2);
  friend Relation *projection(Relation *R1, list<string> projectattrs);
  friend Relation *selection(Relation *R1, DNFformula *f);
  friend Relation *rename(Relation *R1, string s1, string s2);
  friend Relation *join(Relation *R1, Relation *R2, list<string> joinattr);
  friend void print(Relation *R);
  friend bool search(Record *lhs, Record *rhs);

  friend class intattr;
  friend class dobattr;
  friend class floattr;
  friend class strattr;
};





class intattr : public Attr
{

public:
  int val;
  intattr(int i = 0);

  ~intattr();

  bool operator==(const Attr &right) override;

  bool operator!=(const Attr &right) override;

  bool operator>=(const Attr &right) override;

  bool operator<=(const Attr &right) override;

  bool operator<(const Attr &right) override;

  bool operator>(const Attr &right) override;
  friend Relation *uni(Relation *R1, Relation *R2);
  friend Relation *difference(Relation *R1, Relation *R2);
  friend Relation *cartprod(Relation *R1, Relation *R2);
  friend Relation *projection(Relation *R1, list<string> projectattrs);
  friend Relation *selection(Relation *R1, DNFformula *f);
  friend Relation *rename(Relation *R1, string s1, string s2);
  friend class Record;
  friend Relation *join(Relation *R1, Relation *R2, list<string> joinattr);
  friend void print(Relation *R);

  friend class Relation;
};

class floattr : public Attr
{

public:
  float val;
  floattr(float i = 0.0);

  ~floattr();

  bool operator==(const Attr &right) override;

  bool operator!=(const Attr &right) override;
  bool operator>=(const Attr &right) override;
  
  bool operator<=(const Attr &right) override;
  

  bool operator>(const Attr &right) override;

  bool operator<(const Attr &right) override;
  friend Relation *uni(Relation *R1, Relation *R2);
  friend Relation *difference(Relation *R1, Relation *R2);
  friend Relation *cartprod(Relation *R1, Relation *R2);
  friend Relation *projection(Relation *R1, list<string> projectattrs);
  friend Relation *selection(Relation *R1, DNFformula *f);
  friend Relation *rename(Relation *R1, string s1, string s2);
  friend Relation *join(Relation *R1, Relation *R2, list<string> joinattr);
  friend void print(Relation *R);
  friend class Record;
  friend bool search(Record *lhs, Record *rhs);

  friend class Relation;
};

class dobattr : public Attr
{

public:
  double val;
  dobattr(double i = 0.0) ;
  ~dobattr();

  bool operator==(const Attr &right) override;

  bool operator!=(const Attr &right) override;

  bool operator>=(const Attr &right) override;
  bool operator>(const Attr &right) override;

  bool operator<=(const Attr &right) override;

  bool operator<(const Attr &right) override;
  friend Relation *uni(Relation *R1, Relation *R2);
  friend Relation *difference(Relation *R1, Relation *R2);
  friend Relation *cartprod(Relation *R1, Relation *R2);
  friend Relation *projection(Relation *R1, list<string> projectattrs);
  friend Relation *selection(Relation *R1, DNFformula *f);
  friend Relation *rename(Relation *R1, string s1, string s2);
  friend void print(Relation *R);
  friend class Record;
  friend bool search(Record *lhs, Record *rhs);

  friend class Relation;
};

class strattr : public Attr
{

public:
  string val;
  strattr(string &v);
  ~strattr() ;

  bool operator<(const Attr &right) override;

  bool operator>(const Attr &right) override;
  bool operator<=(const Attr &right) override ;
  bool operator>=(const Attr &right) override
 ;
  bool operator==(const Attr &right) override
  ;
  bool operator!=(const Attr &right) override
  ;
  friend class Relation;
  friend Relation *uni(Relation *R1, Relation *R2);
  friend Relation *difference(Relation *R1, Relation *R2);
  friend Relation *cartprod(Relation *R1, Relation *R2);
  friend Relation *projection(Relation *R1, list<string> projectattrs);
  friend Relation *selection(Relation *R1, DNFformula *f);
  friend Relation *rename(Relation *R1, string s1, string s2);
  friend Relation *join(Relation *R1, Relation *R2, list<string> joinattr);
  friend void print(Relation *R);
  friend bool search(Record *lhs, Record *rhs);
  friend class Record;
};





 Relation *uni(Relation *R1, Relation *R2);
 Relation *difference(Relation *R1, Relation *R2);
 Relation *cartprod(Relation *R1, Relation *R2);
 Relation *projection(Relation *R1, list<string> projectattrs);
 Relation *selection(Relation *R1, DNFformula *f);
 Relation *rename(Relation *R1, string s1, string s2);
 Relation *join(Relation *R1, Relation *R2, list<string> joinattr);
 void print(Relation *R);
 bool search(Record *lhs, Record *rhs);