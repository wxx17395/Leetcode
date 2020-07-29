#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 动态规划
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (int i = n - 1; i >= 0; --i){
            for (int j = m - 1; j >= 0; --j){
                dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main() {
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    cout << Solution().findLength(A, B) << endl;
    return 0;
}
