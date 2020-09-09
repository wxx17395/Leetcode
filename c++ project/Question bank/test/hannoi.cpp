#include <bits/stdc++.h>
using namespace std;

void Move(int n, char src, char dst){
    cout << "Move " << n << " from " << src << " to " << dst << endl;
}

void Hannoi(int n, char a, char b, char c){
    if (n == 1){
        Move(n, a, c);
        return;
    }
    Hannoi(n - 1, a, c, b);
    Move(n, a, c);
    Hannoi(n - 1, b, a, c);
}

int main()
{
    Hannoi(3, 'a', 'b', 'c');
    return 0;
}
