#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> cur;
    int n, k;
    void backtrace(int x){
        if (cur.size() == k){
            res.emplace_back(cur);
            return;
        }
        for (int i = x; i <= n; ++i){
            cur.push_back(i);
            backtrace(i + 1);
            cur.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        backtrace(1);
        return res;
    }
};

int main()
{
    
    return 0;
}
