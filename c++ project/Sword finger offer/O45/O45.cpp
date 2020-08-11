#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return (sa + sb) < (sb + sa);
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string s;
        for (auto n : nums){
            s += to_string(n);
        }
        return s;
    }
};

int main()
{
    vector<int> nums{3,30,34,5,9};
    cout << Solution().minNumber(nums) << endl; 
    return 0;
}
