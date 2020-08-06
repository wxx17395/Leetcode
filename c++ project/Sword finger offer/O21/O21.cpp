#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j){
            while (i < j && (nums[i] & 1) == 1){
                ++i;
            }
            while (i < j && (nums[j] & 1) == 0){
                --j;
            }
            if (i >= j){
                break;
            }
            swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};

int main()
{
    vector<int> nums{1,2,3,4};
    Solution().exchange(nums);
    return 0;
}
