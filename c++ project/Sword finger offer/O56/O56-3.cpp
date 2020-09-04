#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumbers(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            res = res ^ nums[i];
        }
        return res;
    }
};

int main()
{
    vector<int> nums{1,1,6,2,2,3,3};
    cout << Solution().singleNumbers(nums) << endl;
    return 0;
}
