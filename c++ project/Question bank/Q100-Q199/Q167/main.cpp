#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i < j){
            if (target - numbers[i] < numbers[j]){
                --j;
            } else if (target - numbers[i] > numbers[j]){
                ++i;
            } else {
                break;
            }
        }
        return {i + 1, j + 1};
    }
};

int main() {
    vector<int> nums{-1,0};
    Solution().twoSum(nums, -1);
    return 0;
}
