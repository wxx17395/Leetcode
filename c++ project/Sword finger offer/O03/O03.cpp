#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> a(nums.size());
        int res;
        for (auto num : nums){
            if (a[num] > 0){
                res = num;
                break;
            }
            ++a[num];
        }
        return res;
    }
};

int main()
{
    
    return 0;
}
