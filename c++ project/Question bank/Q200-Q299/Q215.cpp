#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int i = nums.size() - 1;
       for (; i > nums.size() - k; --i);
       return nums[i];
    }
};


int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << Solution().findKthLargest(nums, 4) << endl;
    return 0;
}
