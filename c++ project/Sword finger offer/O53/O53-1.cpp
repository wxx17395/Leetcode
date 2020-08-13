#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        return upper_bound(nums.begin(), nums.end(),target) - lower_bound(nums.begin(), nums.end(), target);
    }
};

int main()
{
    
    return 0;
}
