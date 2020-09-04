#include <bits/stdc++.h>
using namespace std;

/*class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LONG_LONG_MAX));
        vector<long long> sub (n + 1, 0);
        for (int i = 0; i < n; ++i){
            sub[i + 1] = sub[i] + nums[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= min(i, m); ++j){
                for (int k = 0; k < i; ++k){
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return dp[n][m];
    }
};*/

class Solution {
private:
    bool check(vector<int> &nums, int x, int m){
        long long sum = 0;
        int cnt = 1;
        for (auto num : nums){
            if (sum + num > x){
                ++cnt;
                sum = num;
            } else{
                sum += num;
            }
        }
        return cnt <= m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto num : nums){
            right += num;
            if (num > left){
                left = num;
            }
        }
        while (left < right){
            long long mid = (left + right) >> 1;
            if (check(nums, mid ,m)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
