#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find(nums, target) - find(nums, target - 1);
    }

    int find(vector<int>& nums, int target){
        int i = 0, j = nums.size() - 1;
        while (i <= j){
            int m = j + (i - j) / 2;
            if (nums[m] <= target){
                i = m + 1;
            }else{
                j = m - 1;
            }
        }
        return i;
    }

    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j){
            int m = j + (i - j) / 2;
            if (nums[m] == m){
                i = m + 1;
            }else{
                j = m - 1;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums = {0,1,2,4,5};
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}
