#include <bits/stdc++.h>
using namespace std;

struct A{
    vector<int> a;
    A(){
        for (int i = 0; i < 5; ++i){
            a.push_back(i);
        }
    }
    void printa(){
        cout << &a << endl;
    }
};

struct B{
    set<int> a;
    B(){
        for (int i = 0; i < 5; ++i){
            a.insert(i);
        }
    }
    void printa(){
        cout << &a << endl;
    }
};

int main() {
    A a1;
    A a2(a1);
    a1.printa();
    a2.printa();
    B b1;
    B b2(b1);
    b1.printa();
    b2.printa();
    return 0;
}
