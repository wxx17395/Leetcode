#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int> &output, int first, int len){
        if (first == len){
            res.emplace_back(output);
            return;
        }
        unordered_set<int> used;
        for (int i = first; i < len; ++i){
            if (used.find(output[i]) != used.end()){
                continue;
            }
            swap(output[i], output[first]);
            backtrack(output, first + 1, len);
            swap(output[i], output[first]);
            used.insert(output[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0, nums.size());
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,2};
    Solution().permuteUnique(nums);
    return 0;
}
