#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        if (s.empty()){
            return false;
        }
        bool hasNum = false, hasFuhao = false, hasPoint = false, hasE = false;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '+' || s[i] =='-'){
                if (hasFuhao || !( i == 0 || (hasE && s[i - 1] == 'e'))){
                    return false;
                }
                hasFuhao = true;
            } else if (s[i] == '.'){
                if (hasPoint || hasE) {
                    return false;
                }
                hasPoint = true;
            } else if (s[i] == 'e'){
                if (!hasNum || hasE){
                    return false;
                }
                hasE = true;
                hasNum = false;
                hasFuhao = false;
            } else if (s[i] >= '0' && s[i] <= '9'){
                hasNum = true;
            } else {
                return false;
            }
        }
        return hasNum;
    }
};

int main()
{

    cout << Solution().isNumber(string(" 005047e+6")) << endl;

    return 0;
}
