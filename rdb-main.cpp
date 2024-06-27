#include"rdb.h"
using namespace std;

void instruction()
{
  // cout<<"To create empty table type create "<<endl;
  cout << "To Delete existing table type del" << endl;
  cout << "TO add a Record to table type addrec" << endl;
  cout << "To print existing table type print " << endl;
  cout << "For Union type uni" << endl;
  cout << "For Difference type diff" << endl;
  cout << "For Projection type proj" << endl;
  cout << "For cartproduct type cart" << endl;
  cout << "For instruction type guide" << endl;
  cout << "For rename type rename" << endl;
  cout << "To exit type exit" << endl;
  cout << "To select type select" << endl;
  cout << "For naturaljoin type join" << endl;
}

void print(Relation *R)
{

  for (int i = 0; i < R->nattr; i++)
  {
    cout << left << setw(12) << R->attrnames[i];
  }
  cout << endl;
  for (int i = 0; i < R->nrecs; i++)
  {
    for (int j = 0; j < R->nattr; j++)
    {

      if (R->getrecord(i)->a[j] == 1)
      {
        auto l1 = dynamic_cast<intattr *>(R->getrecord(i)->attrptr[j]);
        cout << left << setw(12) << l1->val;
      }

      if (R->getrecord(i)->a[j] == 2)
      {
        auto l2 = dynamic_cast<dobattr *>(R->getrecord(i)->attrptr[j]);
        cout << left << setw(12) << l2->val;
      }

      if (R->getrecord(i)->a[j] == 3)
      {
        auto l3 = dynamic_cast<strattr *>(R->getrecord(i)->attrptr[j]);
        cout << left << setw(12) << l3->val;
      }
    }
    cout << endl;
  }
}

int main()
{
  instruction();

  vector<Relation *> re;
  while (1)
  {
    string s;
    cout << "Enter string " << endl;
    cin >> s;
    if (s == "addrec")
    {

      if (re.size() != 0)
      {
      label3:
        cout << "Enter table no for record to be added" << endl;
        int t;
        cin >> t;
        if (t == re.size())
        {
          int nattr;
          cout << "Number of attributes: " << endl;
          cin >> nattr;
          vector<string> schema;
          for (int i = 0; i < nattr; i++)
          {
            cout << "Enter attribute name" << endl;
            string s;
            cin >> s;
            schema.push_back(s);
          }
          vector<int> attrinds;
          for (int i = 0; i < nattr; i++)
          {
            attrinds.push_back(i);
          }

          map<string, int> m;
          for (int i = 0; i < nattr; i++)
          {
            m[schema[i]] = 0;
          }
          int i = 0;
          for (auto &vp : m)
          {
            vp.second = i;
            i++;
          }

          map<string, int>::iterator vp;
          vp = m.begin();
          for (int i = 0; i < nattr; i++)
          {
            schema[i] = (*vp).first;
            attrinds[i] = (*vp).second;
            vp++;
          }
          vector<Attr *> v(nattr); // storing attr pointer

          vector<int> p(nattr); // storing attribute types

          Relation *relation = new Relation(schema, attrinds);
          list<Record *> rec;

          map<string, int>::iterator it;
          it = m.begin();

          for (int i = 0; i < nattr; i++)
          {
          label4:
            cout << "\n enter 1 if intattr type for " << (*it).first << endl;
            cout << " enter 2 if dobattr type for " << (*it).first << endl;
            cout << " enter 3 if strattr type for " << (*it).first << endl;
            // Enter the attribute types for schema and value stored

            cin >> p[i];
            if (p[i] == 1)
            {
              int val;
              cout << "Enter value to be stored" << endl;
              cin >> val;
              intattr *z = new intattr(val);
              v[i] = z;
            }
            else if (p[i] == 2)
            {
              double val;
              cout << "Enter value to be stored" << endl;
              cin >> val;
              dobattr *z = new dobattr(val);
              v[i] = z;
            }
            else if (p[i] == 3)
            {
              string val;
              cout << "Enter string" << endl;
              cin >> val;
              strattr *z = new strattr(val);
              v[i] = z;
            }
            else
            {
              cout << "invalid!!\n"
                   << "Enter again" << endl;
              goto label4;
            }
            it++;
          }
          Record *record = new Record(p);
          record->setattr(v);
          relation->addrec(record);
          re.push_back(relation);
          continue;
        }
        if (t < re.size())
        {
          vector<Attr *> v(re[t]->nattr); // storing attr pointer
          vector<int> p(re[t]->nattr);    // storing attribute types

          for (int i = 0; i < re[t]->nattr; i++)
          {
          label2:
            cout << "\n enter 1 if intattr type for " << re[t]->attrnames[i] << endl;
            cout << " enter 2 if dobattr type for " << re[t]->attrnames[i] << endl;
            cout << " enter 3 if strattr type for " << re[t]->attrnames[i] << endl;
            // Enter the attribute types for schema and value stored

            cin >> p[i];
            if (p[i] == 1)
            {
              int val;
              cout << "Enter value to be stored" << endl;
              cin >> val;
              intattr *z = new intattr(val);
              v[i] = z;
            }
            else if (p[i] == 2)
            {
              double val;
              cout << "Enter value to be stored" << endl;
              cin >> val;
              dobattr *z = new dobattr(val);
              v[i] = z;
            }
            else if (p[i] == 3)
            {
              string val;
              cout << "Enter string" << endl;
              cin >> val;
              strattr *z = new strattr(val);
              v[i] = z;
            }
            else
            {
              cout << "invalid!!\n"
                   << "Enter again" << endl;
              goto label2;
            }
          }
          Record *record = new Record(p);
          record->setattr(v);

          re[t]->addrec(record);
          continue;
        }

        if (t > re.size())
        {
          cout << "Invalid table no" << endl;
          goto label3;
        }
      }

      else
      {
        int nattr;
        cout << "Number of attributes: " << endl;
        cin >> nattr;
        vector<string> schema;
        for (int i = 0; i < nattr; i++)
        {
          cout << "Enter attribute name" << endl;
          string s;
          cin >> s;
          schema.push_back(s);
        }
        vector<int> attrinds;
        for (int i = 0; i < nattr; i++)
        {
          attrinds.push_back(i);
        }

        map<string, int> m;
        for (int i = 0; i < nattr; i++)
        {
          m[schema[i]] = 0;
        }
        int i = 0;
        for (auto &vp : m)
        {
          vp.second = i;
          i++;
        }

        map<string, int>::iterator vp;
        vp = m.begin();
        for (int i = 0; i < nattr; i++)
        {
          schema[i] = (*vp).first;
          attrinds[i] = (*vp).second;
          vp++;
        }
        vector<Attr *> v(nattr); // storing attr pointer

        vector<int> p(nattr); // storing attribute types

        Relation *relation = new Relation(schema, attrinds);
        list<Record *> rec;

        map<string, int>::iterator it;
        it = m.begin();

        for (int i = 0; i < nattr; i++)
        {
        label:
          cout << "\n enter 1 if intattr type for " << (*it).first << endl;
          cout << " enter 2 if dobattr type for " << (*it).first << endl;
          cout << " enter 3 if strattr type for " << (*it).first << endl;
          // Enter the attribute types for schema and value stored

          cin >> p[i];
          if (p[i] == 1)
          {

            int val;
            cout << "Enter value to be stored" << endl;
            cin >> val;
            intattr *z = new intattr(val);
            v[i] = z;
          }
          else if (p[i] == 2)
          {
            double val;
            cout << "Enter value to be stored" << endl;
            cin >> val;
            dobattr *z = new dobattr(val);
            v[i] = z;
          }
          else if (p[i] == 3)
          {
            string val;
            cout << "Enter string" << endl;
            cin >> val;
            strattr *z = new strattr(val);
            v[i] = z;
          }
          else
          {
            cout << "invalid!!\n"
                 << "Enter again" << endl;
            goto label;
          }
          it++;
        }
        Record *record = new Record(p);
        record->setattr(v);

        relation->addrec(record);
        re.push_back(relation);
        // print (re[0]);
      }

      continue;
    }

    if (s == "del")
    {
      cout << "Enter table no to delete" << endl;
      int x;
      cin >> x;
      vector<Relation *>::iterator it;
      it = re.begin() + x;
      re.erase(it);
    }

    if (s == "uni")
    {
      cout << "enter table no 1" << endl;
      int a, b;
      cin >> a;
      cout << "enter table no 2" << endl;
      cin >> b;
      re.push_back(uni(re[a], re[b]));
    }
    if (s == "diff")
    {
      int a, b;
      cout << "enter table no 1" << endl;
      cin >> a;
      cout << "enter table no 2" << endl;
      cin >> b;
      re.push_back(difference(re[a], re[b]));
    }

    if (s == "cartprod")
    {
      int a, b;
      cout << "enter table no 1" << endl;
      cin >> a;
      cout << "enter table no 2" << endl;
      cin >> b;
      re.push_back(cartprod(re[a], re[b]));
    }

    if (s == "proj")
    {
      int a, b;
      cout << "enter table no" << endl;
      cin >> a;
      list<string> projectattrs;
      cout << "Enter no of strings" << endl;
      cin >> b;
      for (int l = 0; l < b; l++)
      {
        string s;
        cout << "enter string" << endl;
        cin >> s;
        projectattrs.push_back(s);
      }
      re.push_back(projection(re[a], projectattrs));
    }

    if (s == "rename")
    {
      cout << "Enter table no" << endl;
      int n;
      cin >> n;
      string s1, s2;
      cout << "enter 1st string" << endl;
      cin >> s1;
      cout << "enter 2nd string" << endl;
      cin >> s2;
      re.push_back(rename(re[n], s1, s2));
    }

    if (s == "select")
    {
      cout << "Enter table no" << endl;
      int n;
      cin >> n;
      DNFformula *f = new DNFformula();
      cout << "Enter no of disjunctions" << endl;
      int dis;
      cin >> dis;

      for (int i = 0; i < dis; i++)
      {
        cout << "Enter no of conjunctions" << endl;
        int con;
        cin >> con;
        list<tuple<string, char, Attr *>> y;

        for (int j = 0; j < con; j++)
        {

          cout << "Enter attribute name" << endl;
          string s;
          cin >> s;
          cout << "Enter char" << endl;
          char c;
          cin >> c;

          cout << "If attribute type is int enter 1" << endl;
          cout << "If attribute type is dob enter 2" << endl;
          cout << "If attribute type is str enter 3" << endl;
          cout << "Enter attribute type no" << endl;
          int r;
          cin >> r;

          Attr *g = nullptr;
          tuple<string, char, Attr *> h;
          if (r == 1)
          {
            cout << "Enter value stored in Attr" << endl;
            int v;
            cin >> v;

            g = new intattr(v);
          }

          if (r == 2)
          {
            cout << "Enter value stored in Attr" << endl;
            double v;
            cin >> v;

            g = new dobattr(v);
          }

          if (r == 3)
          {
            cout << "Enter value stored in Attr" << endl;
            string v;
            cin >> v;

            g = new strattr(v);
          }

          h = make_tuple(s, c, g);
          y.push_back(h);
        }

        f->ops.push_back(y);
      }

      re.push_back(selection(re[n], f));
    }

    if (s == "join")
    {
      cout << "Enter table no" << endl;
      int n;
      cin >> n;
      cout << "Enter table no" << endl;
      int p;
      cin >> p;

      list<string> st;
      cout << "Enter no of attributes" << endl;
      int e;
      cin >> e;

      for (int i = 0; i < e; i++)
      {
        cout << "Enter string" << endl;
        string s;
        cin >> s;
        st.push_back(s);
      }

      re.push_back(join(re[n], re[p], st));
    }

    if (s == "guide")
    {
      instruction();
    }

    if (s == "print")
    {
      cout << "Enter table no" << endl;
      int n;
      cin >> n;
      print(re[n]);
    }

    if (s == "exit")
    {
      break;
    }
  }
}

