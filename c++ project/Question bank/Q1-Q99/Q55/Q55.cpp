#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
         int rightmost = 0;
         for (int i = 0; i < n; ++i){
             if (i <= rightmost){
                 rightmost = max(rightmost, i + nums[i]);
                 if (rightmost >= n - 1){
                     return true;
                 }
             }
         }
         return false;
    }
};

int main()
{
    vector<int> nums{1,2,3};
    cout << Solution().canJump(nums) << endl;
    return 0;
}
