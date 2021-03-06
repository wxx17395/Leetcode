#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                dp[i][j] = grid[i][j];
                if (i == 0 && j == 0){
                    continue;
                } else if (i == 0){
                    dp[i][j] += dp[i][j - 1];
                } else if (j == 0){
                    dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    
    return 0;
}
