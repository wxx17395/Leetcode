#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int mid;
        while (i <= j){
            mid = i + (j - i) / 2;
            if (nums[mid] < target){
                i = mid + 1;
            } else if (nums[mid] > target){
                j = mid;
            } else{
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{-1,0,3,5,9,12};
    cout << Solution().search(nums, 2) << endl;
    return 0;
}
