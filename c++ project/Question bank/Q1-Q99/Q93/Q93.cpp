#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> res;
    void backtrace(string s,vector<string> &cur, int l){
        if (cur.size() == 4){
            if (l != s.size()){
                return;
            } else {
                string tmp;
                for (int i = 0; i < 3; ++i){
                    tmp += cur[i] + ".";
                }
                tmp += cur[3];
                res.push_back(tmp);
                return;
            }
        }
        for (int i = 1; i <= 3; ++i){
            if (l >= s.size()){
                return;
            }
            if (i != 1 && s[l] == '0'){
                return;
            }
            string str = s.substr(l, i);
            if (i == 3 && str > "255"){
                return;
            }
            cur.push_back(str);
            backtrace(s, cur, l + i);
            cur.pop_back();
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> cur;
        backtrace(s, cur, 0);
        return res;
    }
};

int main()
{
    
    return 0;
}
