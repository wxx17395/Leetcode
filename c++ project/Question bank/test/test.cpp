#include <bits/stdc++.h>
using namespace std;

void fun(shared_ptr<int> p){
    *p = 5;
}

int main()
{
    int ar = 6;
    for (int i = 0; i < 100; ++i){
        shared_ptr<int> p = make_shared<int>(ar);
        fun(p);
        cout << i << ";" <<  *p << endl;
    }
    return 0;
}
