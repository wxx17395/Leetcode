#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> cur;
    void backtrace(vector<int>& candidates, int target, int x){
        if (target == 0){
            res.push_back(cur);
        }
        if (target < 0){
            return;
        }
        for (int i = x; i < candidates.size(); ++i){
            if (i > x && candidates[i - 1] == candidates[i]){
                continue;
            }
            cur.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return res;
    }
};

int main()
{
    
    return 0;
}
