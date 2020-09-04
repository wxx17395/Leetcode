#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, cur = 0, minl = INT_MAX;
        while ( r < n ){
            cur += nums[r];
            while (cur >= s){
                minl = min(minl, r - l + 1);
                cur -= nums[l];
                ++l;
            }
            ++r;
        }
        return minl == INT_MAX ? 0 : minl;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    cout << Solution().minSubArrayLen(7, nums) << endl;
    return 0;
}
