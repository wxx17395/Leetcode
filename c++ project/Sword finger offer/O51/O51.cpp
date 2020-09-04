#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> cp(nums.size(), 0);
        merge_sort(nums, cp, 0, nums.size() - 1);
        return count;
    }

private:
    void merge_sort(vector<int> &nums, vector<int> &cp, int left, int right){
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        merge_sort(nums, cp, left, mid);
        merge_sort(nums,cp, mid + 1, right);
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right){
            if (nums[j] < nums[i]){
                cp[k++] = nums[j++];
                count += (mid - i + 1);
            }else{
                cp[k++] = nums[i++];
            }
        }
        if (i <= mid) copy(nums.begin() + i, nums.begin() + mid + 1, cp.begin() + k);
        if (j <= right) copy(nums.begin() + j, nums.begin() + right + 1, cp.begin() + k);
        copy(cp.begin() + left, cp.begin() + right + 1, nums.begin() + left);
    }
};


int main() {
    vector<int> nums{1,2,1,2,1};
    cout << Solution().reversePairs(nums) << endl;
    return 0;
}
