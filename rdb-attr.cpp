#include"rdb.h"
using namespace std;


 
 intattr:: intattr(int i) : val(i) {}

  intattr::~intattr() {}

  bool intattr::operator==(const Attr &right) 
  {
    // Check that the right object is an intattr
    if (const intattr *rhs = dynamic_cast<const intattr *>(&right))
    {
      return val == rhs->val;
    }
    // The right object is not an intattr, so return false
    return false;
  }

  bool intattr:: operator!=(const Attr &right) 
  {
    // Check that the right object is an intattr
    if (const intattr *rhs = dynamic_cast<const intattr *>(&right))
    {
      return val != rhs->val;
    }
    // The right object is not an intattr, so return false
    return false;
  }

  bool intattr:: operator>=(const Attr &right) 
  {
    // Check that the right object is an intattr
    if (const intattr *rhs = dynamic_cast<const intattr *>(&right))
    {
      return val >= rhs->val;
    }
    // The right object is not an intattr, so return false
    return false;
  }

  bool intattr:: operator<=(const Attr &right) 
  {
    // Check that the right object is an intattr
    if (const intattr *rhs = dynamic_cast<const intattr *>(&right))
    {
      return val <= rhs->val;
    }
    // The right object is not an intattr, so return false
    return false;
  }

  bool intattr:: operator<(const Attr &right) 
  {
    // Check that the right object is an intattr
    if (const intattr *rhs = dynamic_cast<const intattr *>(&right))
    {
      return val < rhs->val;
    }
    // The right object is not an intattr, so return false
    return false;
  }

  bool intattr:: operator>(const Attr &right) 
  {
    // Check that the right object is an intattr
    if (const intattr *rhs = dynamic_cast<const intattr *>(&right))
    {
      return val > rhs->val;
    }
    // The right object is not an intattr, so return false
    return false;
  }





  floattr:: floattr(float i ) : val(i) {}

 floattr:: ~floattr() {}

  bool floattr:: operator==(const Attr &right) 
  {
    // Check that the right object is an floattr
    if (const floattr *rhs = dynamic_cast<const floattr *>(&right))
    {
      return val == rhs->val;
    }
    // The right object is not an floattr, so return false
    return false;
  }

  bool floattr:: operator!=(const Attr &right) 
  {
    // Check that the right object is an floattr
    if (const floattr *rhs = dynamic_cast<const floattr *>(&right))
    {
      return val != rhs->val;
    }
    // The right object is not an floattr, so return false
    return false;
  }

  bool floattr:: operator>=(const Attr &right) 
  {
    // Check that the right object is an floattr
    if (const floattr *rhs = dynamic_cast<const floattr *>(&right))
    {
      return val >= rhs->val;
    }
    // The right object is not an floattr, so return false
    return false;
  }

  bool floattr:: operator<=(const Attr &right) 
  {
    // Check that the right object is an floattr
    if (const floattr *rhs = dynamic_cast<const floattr *>(&right))
    {
      return val <= rhs->val;
    }
    // The right object is not an floattr, so return false
    return false;
  }

  bool floattr:: operator>(const Attr &right) 
  {
    // Check that the right object is an floattr
    if (const floattr *rhs = dynamic_cast<const floattr *>(&right))
    {
      return val > rhs->val;
    }
    // The right object is not an floattr, so return false
    return false;
  }

  bool  floattr::operator<(const Attr &right) 
  {
    // Check that the right object is an floattr
    if (const floattr *rhs = dynamic_cast<const floattr *>(&right))
    {
      return val < rhs->val;
    }
    // The right object is not an floattr, so return false
    return false;
  }
  




 
 dobattr:: dobattr(double i ) : val(i) {}
  dobattr::~dobattr() {}

  bool  dobattr::operator==(const Attr &right) 
  {
    // Check that the right object is an dobattr
    if (const dobattr *rhs = dynamic_cast<const dobattr *>(&right))
    {
      return val == rhs->val;
    }
    // The right object is not an dobattr, so return false
    return false;
  }

  bool dobattr:: operator!=(const Attr &right) 
  {
    // Check that the right object is an dobattr
    if (const dobattr *rhs = dynamic_cast<const dobattr *>(&right))
    {
      return val != rhs->val;
    }
    // The right object is not an dobattr, so return false
    return false;
  }

  bool  dobattr::operator>=(const Attr &right) 
  {
    // Check that the right object is an dobattr
    if (const dobattr *rhs = dynamic_cast<const dobattr *>(&right))
    {
      return val >= rhs->val;
    }
    // The right object is not an dobattr, so return false
    return false;
  }

  bool dobattr::operator>(const Attr &right) 
  {
    // Check that the right object is an dobattr
    if (const dobattr *rhs = dynamic_cast<const dobattr *>(&right))
    {
      return val > rhs->val;
    }
    // The right object is not an dobattr, so return false
    return false;
  }

  bool dobattr:: operator<=(const Attr &right) 
  {
    // Check that the right object is an dobattr
    if (const dobattr *rhs = dynamic_cast<const dobattr *>(&right))
    {
      return val <= rhs->val;
    }
    // The right object is not an dobattr, so return false
    return false;
  }

  bool  dobattr::operator<(const Attr &right)
  {
    // Check that the right object is an dobattr
    if (const dobattr *rhs = dynamic_cast<const dobattr *>(&right))
    {
      return val < rhs->val;
    }
    // The right object is not an dobattr, so return false
    return false;
  }
 


 strattr::  strattr(string &v) : val(v) {}
  strattr::  ~strattr() {}

  bool strattr::   operator<(const Attr &right)
  {
    // Check that the right object is an strattr
    if (const strattr *rhs = dynamic_cast<const strattr *>(&right))
    {
      return val < rhs->val;
    }
    // The right object is not an strattr, so return false
    return false;
  }

  bool strattr::   operator>(const Attr &right) 
  {
    // Check that the right object is an strattr
    if (const strattr *rhs = dynamic_cast<const strattr *>(&right))
    {
      return val > rhs->val;
    }
    // The right object is not an strattr, so return false
    return false;
  }
  bool  strattr::  operator<=(const Attr &right) 
  {
    // Check that the right object is an strattr
    if (const strattr *rhs = dynamic_cast<const strattr *>(&right))
    {
      return val <= rhs->val;
    }
    // The right object is not an strattr, so return false
    return false;
  }
  bool strattr::   operator>=(const Attr &right) 
  {
    // Check that the right object is an strattr
    if (const strattr *rhs = dynamic_cast<const strattr *>(&right))
    {
      return val >= rhs->val;
    }
    // The right object is not an strattr, so return false
    return false;
  }
  bool strattr::   operator==(const Attr &right) 
  {
    // Check that the right object is an strattr
    if (const strattr *rhs = dynamic_cast<const strattr *>(&right))
    {
      return val == rhs->val;
    }
    // The right object is not an strattr, so return false
    return false;
  }
  bool strattr::   operator!=(const Attr &right) 
  {
    // Check that the right object is an strattr
    if (const strattr *rhs = dynamic_cast<const strattr *>(&right))
    {
      return val != rhs->val;
    }
    // The right object is not an strattr, so return false
    return false;
  }
 
 
 Record:: Record(vector<int> &c)
  {
    for (int i = 0; i < c.size(); i++)
    {
      a.push_back(c[i]);
      attrptr.push_back(nullptr);
    }
  }
  Record::Record(Record &c) : attrptr(c.attrptr), a(c.a) {}
 Record &Record:: operator=(Record &c)
  {
    attrptr = c.attrptr;
    a = c.a;
    return *this;
  }

  void Record::setattr(vector<Attr *> &v)
  {
    attrptr = v;
  }

 Record:: ~Record()
  {
    for (auto ptr : attrptr)
    {
      delete ptr;
    }
    attrptr.clear();
    a.clear();
  }

      // list of records
 Relation:: Relation(vector<string> &v, vector<int> &r) : nrecs(0), nattr(v.size())
  {
    for (int i = 0; i < v.size(); i++)
    {
      attrnames.push_back(v[i]);
      attrinds.push_back(r[i]);
    }
  }

  void Relation:: addrec(Record *reco)
  {
    recs.push_back(reco);
    ++nrecs;
  }
  Record   * Relation::getrecord(int i)
  {
    int j = 0;
    for (auto &g : recs)
    {
      if (j == i)

      {
        return g;
      }
      j++;
    }
    return nullptr;
  }

 