#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<double>>dp(n + 1, vector<double>(6*n + 1, 0));
        vector<double> ans;
        for(int i = 1; i <= n; i ++){
            for(int j = i; j <= 6*i; j ++){
                if(i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int k = 1; k <= 6; k ++){
                    if(j - k >= i - 1) dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for(int i = n; i <= 6*n; i ++){
            ans.push_back(dp[n][i] * pow(1.0/6, n));
        }
        return ans;
    }
};

int main() {
    cout << 1e7 << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
