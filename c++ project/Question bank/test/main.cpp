#include <bits/stdc++.h>
using namespace std;

string& genStr(string& s){
    string ns;
    int n = 0;
    while(n < s.length()){
        ns += string(s[n + 1] - '0', s[n]);
        n += 2;
    }
    return ns;
}

int main()
{
    
    return 0;
}
