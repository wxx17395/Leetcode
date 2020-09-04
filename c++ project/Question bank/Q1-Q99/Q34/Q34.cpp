#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int lower(vector<int> &nums, int target){
        int i = 0, j = nums.size();
        while (i < j){
            int mid = i + (j - i) / 2;
            if (nums[mid] < target){
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i;
    }

    int upper(vector<int> &nums, int target){
        int i = 0, j = nums.size();
        while (i < j){
            int mid = i + (j - i) / 2;
            if (nums[mid] <= target){
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int low = lower(nums, target);
        int high = upper(nums, target);
        if (low == high) return {-1, -1};
        return {low, high - 1};
    }
};

int main()
{
    vector<int> nums{5,7,7,8,8,10};
    
    return 0;
}
