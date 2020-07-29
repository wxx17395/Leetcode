#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (!n){
            return 0;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i = 0,j = 0,k = 0;
        for (int index = 1; index < n ; ++index){
            int temp = min(dp[i] * 2, min (dp[j] * 3, dp[k] * 5));
            if (temp == dp[i] * 2){
                ++i;
            }
            if (temp == dp[j] * 3){
                ++j;
            }
            if (temp == dp[k] * 5){
                ++k;
            }
            dp[index] = temp;
        }
        return dp[n - 1];
    }
};

int main() {
    cout << Solution().nthUglyNumber(7) << endl;
    return 0;
}
