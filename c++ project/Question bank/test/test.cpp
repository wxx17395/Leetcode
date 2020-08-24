#include <bits/stdc++.h>
using namespace std;

struct myi{
   int a, b;
   myi(int x, int y): a(x), b(y){};
   bool operator< (const myi c) const{
      return a + b < c.a + c.b;
   }
};

ostream& operator<< (ostream &os, const myi &a){
   os << a.a << a.b << endl;
   return os;
}

int main()
{
   myi a1(1,2);
   myi a2(2,4);
   myi a3(3,2);
   myi* a = new myi(2,2);
   cout << max({a1,a2,a3});
   vector<myi> vec{a1,a2,a3};
   cout << *max_element(vec.begin(), vec.end());
   return 0;
}
