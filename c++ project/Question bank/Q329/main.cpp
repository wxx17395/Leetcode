#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>>& meno){
        if (meno[i][j] != 0){
            return meno[i][j];
        }
        ++meno[i][j];
        for (int k = 0; k < 4; ++k){
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]){
                meno[i][j] = max(meno[i][j], dfs(matrix, ni, nj, meno) + 1);
            }
        }
        return meno[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return 0;
        }
        m = matrix.size(), n = matrix.begin()->size();
        vector<vector<int>> meno(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                ans = max(ans, dfs(matrix, i, j, meno));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> nums{{9,9,4}, {6,6,8},{2,1,1}};
    cout << Solution().longestIncreasingPath(nums) << endl;
    return 0;
}
