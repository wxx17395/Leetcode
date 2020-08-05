#include <bits/stdc++.h>
using namespace std;

class A{
public:
    void printself(){
        cout << "This is A" << endl;
    }
};

class B: A{
public:
    void printself(){
        cout << "This is B" << endl;
    }

    void printself_a(){
        A::printself();
    }
};

int main()
{
    B b;
    b.printself();
    A* a = (A*)&b;
    //A* a = reinterpret_cast<A*>(&b);
    a->printself();
    try
    {
        int a;
        cin >> a;
        if (a == 0){
            throw 0;
        }
        cout << a << endl;
    }
    catch(int i)
    {
        cout << "0 error!\n" << endl;
        exit(0);
    }
    return 0;
}
