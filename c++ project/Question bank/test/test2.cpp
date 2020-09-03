#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums){
    int n = nums.size();
    vector<int> res(n);
    deque<int> q;
    for (int i = 0; i < n; ++i){
        if (q.empty()){
            q.push_back(i);
            continue;
        }
        while (!q.empty() && nums[i] > nums[q.back()]){
            q.pop_back();
        }
        for (int j = 0; j < q.size(); ++j){
            ++res[q[j]];
        }
        q.push_back(i);
    }
    q.clear();
    for (int i = n - 1; i >= 0; --i){
        if (q.empty()){
            q.push_back(i);
            continue;
        }
        while (!q.empty() && nums[i] > nums[q.back()]){
            q.pop_back();
        }
        for (int j = 0; j < q.size(); ++j){
            ++res[q[j]];
        }
        q.push_back(i);
    }
    for (auto m : res){
        cout << m << endl;
    }
}

int main()
{
    vector<int> nums{5,6,7,8,10};
    helper(nums);
    return 0;
}
