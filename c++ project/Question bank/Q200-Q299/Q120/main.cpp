#include <bits/stdc++.h>
using namespace std;

/*class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        dfs(triangle, 0, 0, 0);
        return res;
    }

private:
    int res = INT_MAX;
    void dfs(vector<vector<int>>& triangle, int i, int j, int cur){
        int n = triangle.size();
        cur += triangle[i][j];
        if (i == n - 1){
            res = min(res, cur);
            return;
        }
        dfs(triangle, i + 1, j, cur);
        dfs(triangle, i + 1, j + 1, cur);
    }
};*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < m; ++i){
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            dp[i][i]= dp[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

int main() {
    vector<vector<int>> triangle{vector<int>{2},vector<int>{3,4},vector<int>{6,5,7},vector<int>{4,1,8,3}};
    cout << Solution().minimumTotal(triangle);
    return 0;
}
