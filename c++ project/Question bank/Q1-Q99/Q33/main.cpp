#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, n = nums.size(), j = n - 1;
        while (i < j){
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[j]){
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        int k = i;
        i = 0, j = n - 1;
        while (i <= j){
            int mid = i + (j - i) / 2;
            if (nums[(mid + k) % n] > target){
                j = mid - 1;
            }else if (nums[(mid + k) % n] < target){
                i = mid + 1;
            }else{
                return (mid + k) % n;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums{4,5,1,2,3};
    cout << Solution().search(nums, 2) << endl;
    return 0;
}
