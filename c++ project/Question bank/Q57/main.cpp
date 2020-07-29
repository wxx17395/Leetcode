#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int cur = nums[l] + nums[r];
            if (cur > target) --r;
            else if (cur < target) ++l;
            else break;
        }
        return {nums[l], nums[r]};
    }

    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> cur;
        int l = 1, sum = 0, end = target / 2 + 1;
        for (int i = 1; i <= end; ++i) {
            sum += i;
            while (sum > target) {
                sum -= l;
                ++l;
            }
            if (sum < target) {
                continue;
            }
            else{
                for(int j = l; j <= i; ++j){
                    cur.push_back(j);
                }
                res.emplace_back(cur);
                cur.clear();
            }
        }
        return res;
    }
};

int main() {
    Solution().findContinuousSequence(9);
    return 0;
}
