#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtrace(vector<int>& nums, int start){
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i){
            if (i > start && nums[i] == nums[i - 1]){
                continue;
            }
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtrace(nums, 0);
        return res;
    }
};

int main()
{
    
    return 0;
}
