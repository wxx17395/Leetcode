#include <bits/stdc++.h>
using namespace std;


struct A{

   int a;

};

struct B:A{

   int b;

};

struct C: B{

   int c;

};

int main()
{
   C c;

   A* a=(A*)&c;

   B* b=(B*)&c;

   if((void * )a == (void *)b){
      cout << "true" << endl;
   } else {
      cout << "false" << endl;
   }
   string s;
   getline(cin, s);
   return 0;
}
