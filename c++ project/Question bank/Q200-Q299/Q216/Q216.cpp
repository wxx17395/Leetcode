#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> cur;
    int k, n;
    void backtrace(int x, int y, int target){
        if (target == 0 && y == k){
            res.push_back(cur);
            return;
        }
        if (target < 0 || y == k){
            return;
        }
        for (int i = x; i <= 9; ++i){
            if (y == 0 && i > 10 - k){
                return;
            }
            cur[y] = i;
            backtrace(i + 1, y + 1, target - i);
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;
        cur.resize(k);
        backtrace(1, 0, n);
        return res;
    }
};

int main()
{
    
    return 0;
}
