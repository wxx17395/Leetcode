#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (const auto num : nums){
            ++mp[num];
        } 
        vector<pair<int, int>> vec;
        for (const auto p : mp){
            vec.push_back({p.first, p.second});
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; ++i){
            res.push_back(vec[i].first);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}
