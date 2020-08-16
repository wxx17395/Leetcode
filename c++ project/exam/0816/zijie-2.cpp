#include <bits/stdc++.h>

using namespace std;

string del = "0010";

int func(string s){
    int first = s.find(del);
    if (first != string::npos){
        int pre = first - 1;
        int post = first + 4;
        if (s[pre] != '1' && s[post] != '1'){
            s.erase(first + 2, 1);
        } else if (s[pre] != '1' && s[post] == '1'){
            s.erase(first + 3, 1);
        } else{
            s.erase(first, 1);
        }
        return 1 + func(s);
    }
    return 0; 
}

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i){
        cin >> s;
        s.push_back('2');
        s.insert(0, "2");
        cout << func(s) << endl;
    }
    return 0;
}
