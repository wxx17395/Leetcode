#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stk;
        vector<int> flag;
        for (int i = 0; i < s.size(); ++i){
            char c = s[i];
            if (c == '('){
                stk.push(i);
            } else if (c == '*'){
                flag.push_back(i);
            } else {
                if (stk.empty()){
                    if (flag.size() == 0){
                        return false;
                    } else {
                        flag.pop_back();
                        continue;
                    }
                }
                stk.pop();
            }
        }
        while (stk.size() > 0 && flag.size() > 0){
            if (stk.top() < flag.back()){
                stk.pop();
                flag.pop_back();
            } else {
                return false;
            }
        }
        return stk.size() <= flag.size();
    }
};

int main()
{
    cout << Solution().checkValidString("(*()") << endl;
    return 0;
}
