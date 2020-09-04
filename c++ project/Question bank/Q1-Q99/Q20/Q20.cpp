#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp; 
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        stack<char> stk;
        for (auto c : s){
            if (c == '(' || c == '[' || c == '{'){
                stk.push(c);
            } else{
                if (stk.empty()){
                    return false;
                }
                if (stk.top() != mp[c]){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main()
{
    string s = "(){}[]";
    cout << Solution().isValid(s) << endl;
    return 0;
}
