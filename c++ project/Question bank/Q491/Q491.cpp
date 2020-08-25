#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    set<vector<int>> st;
    vector<int> cur;
    void dfs(vector<int> &nums,int i){
        if (i == nums.size()){
            return;
        }
        if (cur.empty() || nums[i] >= cur.back()){
            cur.push_back(nums[i]);
            if (cur.size() >= 2){
                st.insert(cur);
            }
            dfs(nums, i + 1);
            cur.pop_back();
        }
        dfs(nums, i + 1);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return vector<vector<int>>(st.begin(), st.end());
    }
};

int main()
{
    vector<int> nums{4,3,2,1};
    vector<vector<int>> res = Solution().findSubsequences(nums);
    return 0;
}
