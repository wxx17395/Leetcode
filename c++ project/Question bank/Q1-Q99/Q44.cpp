#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < m; ++i){
            if (p[i] == '*'){
                dp[0][i + 1] = true;
            }else{
                break;
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (s[i] == p[j] || p[j] == '?'){
                    dp[i + 1][j + 1] = dp[i][j];
                }else if (p[j] == '*'){
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    cout << (true | false) << endl;
    cout << (true || false) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
