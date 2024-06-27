#include"rdb.h"
using namespace std;



// function assumes both records have same 'a'
bool search(Record *lhs, Record *rhs)
{
  bool flag = true;
  for (int i = 0; i < rhs->a.size(); i++)
  {

    // if(this->attrptr[i]->val==rhs->attrptr[i]->val)
    // flag=1;
    if (rhs->a[i] == 1)
    {
      auto l1 = dynamic_cast<intattr *>(lhs->attrptr[i]);
      auto l2 = dynamic_cast<intattr *>(rhs->attrptr[i]);
      if (l1->val != l2->val)
      {
        flag = false;

        break;
      }
    }
    if (rhs->a[i] == 2)
    {
      auto l1 = dynamic_cast<dobattr *>(lhs->attrptr[i]);
      auto l2 = dynamic_cast<dobattr *>(rhs->attrptr[i]);
      if (l1->val != l2->val)
      {
        flag = false;

        break;
      }
    }
    if (rhs->a[i] == 3)
    {
      auto l1 = dynamic_cast<strattr *>(lhs->attrptr[i]);
      auto l2 = dynamic_cast<strattr *>(rhs->attrptr[i]);
      if (l1->val != l2->val)
      {
        flag = false;

        break;
      }
    }
  }
  return flag;
}

 
Relation *selection(Relation *R1, DNFformula *f)
{
  Relation *R = new Relation(R1->attrnames, R1->attrinds);

  for (auto it = f->ops.begin(); it != f->ops.end(); it++)
  {

    for (int j = 0; j < R1->nrecs; j++)
    {

      //int flag = 0;
        int count=0;
      for (auto v = (*it).begin(); v != (*it).end(); v++)
      {
         int flag=0;
        int p;
        for (int l = 0; l < R1->nattr; l++)
        {
          if (get<0>(*v) == R1->attrnames[l])
          {

            p = l; // getting schema index
            break;
          }
        }

        if (get<1>(*v) == '=')
        {
          if (R1->getrecord(0)->a[p] == 1)
          {
            auto l1 = dynamic_cast<intattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<intattr *>(get<2>(*v));
            if (l1->val != l2->val)
            {
              flag = 1;
              break;
            }
          }

          if (R1->getrecord(0)->a[p] == 2)
          {
            auto l1 = dynamic_cast<dobattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<dobattr *>(get<2>(*v));
            if (l1->val != l2->val)
            {
              flag = 1;
              break;
            }
          }

          if (R1->getrecord(0)->a[p] == 3)
          {
            auto l1 = dynamic_cast<strattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<strattr *>(get<2>(*v));
            if (l1->val != l2->val)
            {
              flag = 1;
              break;
            }
          }
        }

        if (get<1>(*v) == '>')
        {

          if (R1->getrecord(0)->a[p] == 1)
          {
            auto l1 = dynamic_cast<intattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<intattr *>(get<2>(*v));
            if (l1->val <= l2->val)
            {
              flag = 1;
              break;
            }
          }

          if (R1->getrecord(0)->a[p] == 2)
          {
            auto l1 = dynamic_cast<dobattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<dobattr *>(get<2>(*v));
            if (l1->val <= l2->val)
            {
              flag = 1;
              break;
            }
          }

          if (R1->getrecord(0)->a[p] == 3)
          {
            auto l1 = dynamic_cast<strattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<strattr *>(get<2>(*v));
            if (l1->val <= l2->val)
            {
              flag = 1;
              break;
            }
          }
        }

        if (get<1>(*v) == '<')
        {

          if (R1->getrecord(0)->a[p] == 1)
          {
            auto l1 = dynamic_cast<intattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<intattr *>(get<2>(*v));
            if (l1->val >= l2->val)
            {
              flag = 1;
              break;
            }
          }

          if (R1->getrecord(0)->a[p] == 2)
          {
            auto l1 = dynamic_cast<dobattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<dobattr *>(get<2>(*v));
            if (l1->val >= l2->val)
            {
              flag = 1;
              break;
            }
          }

          if (R1->getrecord(0)->a[p] == 3)
          {
            auto l1 = dynamic_cast<strattr *>(R1->getrecord(j)->attrptr[p]);
            auto l2 = dynamic_cast<strattr *>(get<2>(*v));
            if (l1->val >= l2->val)
            {
              flag = 1;
              break;
            }
          }
        }

        if(flag==0)
        {
          count++;
        }
      }

      if (count==(*it).size())
      {
        Record *w = new Record(R1->getrecord(0)->a);
        w->setattr(R1->getrecord(j)->attrptr);
        R->addrec(w);
      }
    }
  }

  Relation *P = new Relation(R1->attrnames, R1->attrinds);
  for (int m = 0; m < R->nrecs; m++)
  {
    int flag = 0;
    for (int n = 0; n < m; n++)
    {
      if (search(R->getrecord(m), R->getrecord(n)))
      {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
    {
      P->addrec(R->getrecord(m));
    }
  }
  return P;
}

Relation *rename(Relation *R1, string s1, string s2)
{
  vector<string> s(R1->attrinds.size());
  s = R1->attrnames;
  for (int i = 0; i < R1->attrinds.size(); i++)
  {
    if (R1->attrnames[i] == s1)
    {
      s[i] = s2;
    }
  }
  Relation *R = new Relation(s, R1->attrinds);

  for (int i = 0; i < R1->nrecs; i++)
  {
    Record *w = new Record(R1->recs.front()->a);
    w->setattr(R1->getrecord(i)->attrptr);
    R->addrec(w);
  }

  return R;
}

Relation *projection(Relation *R1, list<string> projectattrs)
{
  vector<string> s(projectattrs.size());
  list<string>::iterator it;
  it = projectattrs.begin();
  for (int i = 0; i < s.size(); i++)
  {
    s[i] = *it;
    it++;
  }
  map<string, int> q;
  for (int i = 0; i < R1->attrinds.size(); i++)
  {
    q[R1->attrnames[i]] = R1->recs.front()->a[i];
  }
  vector<int> sd; // a[i] values in order of s
  map<string, int>::iterator pr;

  for (int i = 0; i < s.size(); i++)
  {
    for (pr = q.begin(); pr != q.end(); pr++)
    {
      if (s[i] == pr->first)
      {
        sd.push_back(pr->second);
        break;
      }
    }
  }

  vector<int> df; // stores indices in order
  for (int i = 0; i < s.size(); i++)
  {
    for (int j = 0; j < R1->attrnames.size(); j++)
    {
      if (s[i] == R1->attrnames[j])
      {
        df.push_back(j);
        break;
      }
    }
  }

  Relation *R = new Relation(s, df);

  for (int i = 0; i < R1->nrecs; i++)
  {
    vector<Attr *> r;
    for (int j = 0; j < s.size(); j++)
    {
      r.push_back(R1->getrecord(i)->attrptr[df[j]]);
    }
    Record *w = new Record(sd);
    w->setattr(r);
    R->addrec(w);
  }

  Relation *P = new Relation(s, df);
  for (int i = 0; i < R->nrecs; i++)
  {
    int flag = 0;
    for (int j = 0; j < i; j++)
    {
      if (search(R->getrecord(i), R->getrecord(j)))
      {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
    {
      P->addrec(R->getrecord(i));
    }
  }

  return P;
}

Relation *cartprod(Relation *R1, Relation *R2)
{
  // assuming both are non empty relations
  int x = R1->attrinds.size() + R2->attrinds.size();
  vector<string> schema(R1->attrinds.size() + R2->attrinds.size());
  vector<int> attrinds(R1->attrinds.size() + R2->attrinds.size());
  int i;
  for (i = 0; i < R1->attrinds.size(); i++)
  {
    schema[i] = R1->attrnames[i];
    attrinds[i] = R1->attrinds[i];
  }

  for (i = R1->attrinds.size(); i < R1->attrinds.size() + R2->attrinds.size(); i++)
  {
    schema[i] = R2->attrnames[i - R1->attrinds.size()];
    attrinds[i] = R2->attrinds[i - R1->attrinds.size()];
  }

  Relation *R = new Relation(schema, attrinds);
  vector<int> g(R1->attrinds.size() + R2->attrinds.size());
  int b;
  for (b = 0; b < R1->attrinds.size(); b++)
  {
    g[b] = R1->recs.front()->a[b];
  }
  for (b = R1->attrinds.size(); b < R1->attrinds.size() + R2->attrinds.size(); b++)
  {
    g[b] = R2->recs.front()->a[b - R1->attrinds.size()];
  }

  for (int l = 0; l < R1->nrecs; l++)
  {

    for (int j = 0; j < R2->nrecs; j++)
    {
      vector<Attr *> v;
      for (int m = 0; m < R1->attrinds.size(); m++)
      {
        v.push_back(R1->getrecord(l)->attrptr[m]);
      }
      for (int m = R1->attrinds.size(); m < x; m++)
      {
        v.push_back(R2->getrecord(j)->attrptr[m - R1->attrinds.size()]);
      }
      Record *w = new Record(g);
      w->setattr(v);

      R->addrec(w);
    }
  }
  return R;
}

Relation *uni(Relation *R1, Relation *R2)
{
  // asuming a relation does not have same records
  if ((*R1).attrnames == (*R2).attrnames && !R1->recs.empty() && !R2->recs.empty() && R1->recs.front()->a == R2->recs.front()->a)
  {
    Relation *R = new Relation(R1->attrnames, R1->attrinds);
    for (auto it = R2->recs.begin(); it != R2->recs.end(); it++)
    {
      R->addrec(*it);
    }
    for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)
    {
      int flag = 1;
      for (auto x = R2->recs.begin(); x != R2->recs.end(); x++)
      {
        if (search(*it, *x))
        {
          flag = 0;

          break;
        }
      }
      if (flag == 1)
      {
        R->addrec(*it);
      }
    }
    return R;
  }
  else
    return nullptr;
}

Relation *difference(Relation *R1, Relation *R2)
{
  if ((*R1).attrnames == (*R2).attrnames && !R1->recs.empty() && !R2->recs.empty() && R1->recs.front()->a == R2->recs.front()->a)
  {
    Relation *R = new Relation(R1->attrnames, R1->attrinds);
    for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)
    {
      int flag = 1;
      for (auto x = R2->recs.begin(); x != R2->recs.end(); x++)
      {
        if (search(*it, *x))
        {
          flag = 0;
          break;
        }
      }
      if (flag == 1)
      {
        R->addrec(*it);
      }
    }

    return R;
  }

  else
    return nullptr;
}

