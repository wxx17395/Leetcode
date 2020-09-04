#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            dp[i] = nums[i] + max(dp[i - 1], 0);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}
