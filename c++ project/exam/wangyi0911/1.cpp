#include <bits/stdc++.h>
using namespace std;

class sigton{
public:
    static sigton& getInstance(){
        static sigton instance;
        return instance;
    }
private:
    sigton(){};
    sigton(const sigton& a);
    sigton operator= (const sigton &a);
};

int main()
{
    sigton& a = sigton::getInstance();
    sigton& b = sigton::getInstance();
    cout << &a << endl;
    cout << &b << endl;
    return 0;
}
