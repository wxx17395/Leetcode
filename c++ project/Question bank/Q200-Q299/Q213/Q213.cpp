#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
    }

    int rob1(vector<int> &nums, int start, int end){
        int pre = 0, cur = 0;
        for (int i = start; i < end; ++i){
            int tmp = cur;
            cur = max(nums[i] + pre, cur);
            pre = tmp;
        }
    }

};

int main()
{
    
    return 0;
}
