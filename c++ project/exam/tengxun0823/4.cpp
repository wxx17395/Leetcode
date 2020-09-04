#include <bits/stdc++.h>
using namespace std;

int res = 0;
int n;

void helper(vector<int> &nums){
    if (nums.empty()){
        return;
    }
    if (nums.size() == 1){
        ++res;
        return;
    }
    int cmin = INT_MAX;
    for(auto num : nums){
        cmin = min(cmin, num);
    }
    if (cmin > nums.size()){
        res += nums.size();
        return;
    }
    res += cmin;
    
    for (auto &num : nums){
        num -= cmin;
    }
    vector<int> zeorIndex;
    zeorIndex.push_back(-1);
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] == 0){
            zeorIndex.push_back(i);
        }
    }
    zeorIndex.push_back(nums.size());
    for (int i = 1; i < zeorIndex.size(); ++i){
        vector<int> next(nums.begin() + zeorIndex[i - 1] + 1, nums.begin() + zeorIndex[i]);
        helper(next);
    } 
}

int main()
{
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    helper(nums);
    cout << res << endl;
    return 0;
}
