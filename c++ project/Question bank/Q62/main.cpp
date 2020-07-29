#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j -1];
            }
        }
        return dp[m][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.begin()->size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (obstacleGrid[i - 1][j -1 ] == 1){
                    dp[i][j] = 0;
                } else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j -1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<vector<int>> nums = {{0,0,0},{0,1,0},{0,0,0}};
    cout << Solution().uniquePathsWithObstacles(nums) << endl;
    return 0;
}
