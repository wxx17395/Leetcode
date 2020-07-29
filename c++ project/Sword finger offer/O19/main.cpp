#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        //dp[0][0] = true;
        for (int i = 0; i < m + 1; ++i){
            for (int j = 0; j < n + 1; ++j){
                if (j == 0) {
                    dp[i][j] = (i == 0);
                    continue;
                }
                if (p[j - 1] != '*'){
                    if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else{
                    if (j >= 2){
                        dp[i][j] = dp[i][j] || dp[i][j - 2];
                    }
                    if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')){
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isMatch(string("aa"), string("a*")) << endl;
    cout << s.isMatch(string("aab"), string("c*a*b")) << endl;
    cout << (true || false) << endl;
    return 0;
}
