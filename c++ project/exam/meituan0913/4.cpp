#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n, s;
    while (1){
        getline(cin, n);
        if (n == "\0") break;
        getline(cin, s);
        int N = stoi(n);
        vector<int> vec;
        for (const auto ch : s){
            vec.push_back(ch - 'A');
        }
    }
    return 0;
}
