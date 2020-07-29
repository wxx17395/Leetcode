#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 栈
    /*int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if (st.empty()){
                    st.push(i);
                }else{
                    res = max(res, i - st.top());
                }
            };
        }
        return res;
    }*/

    // 动态规划
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n,0);
        for (int i = 1; i < n; ++i){
            if (s[i] == ')'){
                if (s[i - 1] == '('){
                    dp[i] = 2;
                    if (i >= 2){
                        dp[i] += dp[i - 2];
                    }
                }else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] >= 2){
                        dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

int main() {
    string s;
    while (cin >> s){
        cout << Solution().longestValidParentheses(s) << endl;
    }
    return 0;
}
