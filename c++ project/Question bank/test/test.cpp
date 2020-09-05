#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s{"abcdabc"};
    int i = 0;
    for (auto c : s){
        i = i ^ c;
    }
    cout << char(i) << endl;
    return 0;
}

