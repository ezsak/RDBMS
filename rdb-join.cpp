#include"rdb.h"
using namespace std;
Relation *join(Relation *R1, Relation *R2, list<string> joinattr)

{

  vector<string> ren; // strings common to both relation in vector
  for (auto it = joinattr.begin(); it != joinattr.end(); it++)
  {
    ren.push_back(*it);
  }
  vector<Relation *> ab;
  Relation *re = new Relation(R2->attrnames, R2->attrinds);
  for (int i = 0; i < R2->nrecs; i++)
  {
    Record *w = new Record(R2->getrecord(0)->a);
    w->setattr(R2->getrecord(i)->attrptr);
    re->addrec(w);
  }
  ab.push_back(re);
  vector<string> t;
  string s;
  for (int i = 0; i < ren.size(); i++) // renaming attributes in R2
  {
    for (int j = 0; j < R2->nattr; j++)
    {
      if (ren[i] == R2->attrnames[j])
      {
        s = ren[i];
        s.push_back('1');
        t.push_back(s);
        ab.push_back(rename(ab[i], R2->attrnames[j], s));
        break;
      }
    }
  }

  ab.push_back(cartprod(R1, ab[ren.size()]));
  vector<int> u; // for R1 attribute indices
  vector<int> d; // for R2 attribute indices

  for (int i = 0; i < ren.size(); i++)
  {
    for (int j = 0; j < ab[ren.size() + 1]->nattr; j++)
    {
      if (ren[i] == ab[ren.size() + 1]->attrnames[j])
      {
        u.push_back(j);
        break;
      }
    }
  }

  for (int i = 0; i < ren.size(); i++)
  {
    for (int j = 0; j < ab[ren.size() + 1]->nattr; j++)
    {
      if (t[i] == ab[ren.size() + 1]->attrnames[j])
      {
        d.push_back(j);
        break;
      }
    }
  }

  struct DNFformula *e = new DNFformula();
  // list<list<tuple<string,char,Attr*>>>jk;

  for (int i = 0; i < ab[ren.size() + 1]->nrecs; i++)
  {
    list<tuple<string, char, Attr *>> x;
    for (int j = 0; j < ren.size(); j++)
    {
      tuple<string, char, Attr *> f;
      f = make_tuple(ren[j], '=', ab[ren.size() + 1]->getrecord(i)->attrptr[u[j]]);
      tuple<string, char, Attr *> df;
      df = make_tuple(t[j], '=', ab[ren.size() + 1]->getrecord(i)->attrptr[u[j]]);
      x.push_back(f);
      x.push_back(df);
    }

    e->ops.push_back(x);
  }

  ab.push_back(selection(ab[ren.size() + 1], e));

  list<string> al;
  for (int i = 0; i < R1->nattr; i++)
  {
    al.push_back(R1->attrnames[i]);
  }

  for (int j = 0; j < R2->nattr; j++)
  {
    int flag = 0;
    for (int i = 0; i < ren.size(); i++)
    {
      if (R2->attrnames[j] == ren[i])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      al.push_back(R2->attrnames[j]);
  }

  return projection(ab[ren.size() + 2], al);
}