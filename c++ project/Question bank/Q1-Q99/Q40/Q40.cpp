#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void backtrace(vector<int>& candidates, vector<int> &cur, int target, int x){
        if (target < 0){
            return;
        }
        if (target == 0){
            res.push_back(cur);
            return;
        }
        for (int i = x; i < candidates.size(); ++i){
            if (i > x && candidates[i] == candidates[i - 1]){
                continue;
            }
            cur.push_back(candidates[i]);
            backtrace(candidates, cur, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrace(candidates, cur, target, 0);
        return res;
    }
};

int main()
{
    
    return 0;
}
