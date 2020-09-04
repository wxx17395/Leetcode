#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int mid;
        while (i <= j){
            mid = i + (j - i) / 2;
            if (nums[mid] == mid){
                i = mid + 1;
            } else{
                j = mid - 1;
            }
        }
        return i;
    }
};

int main()
{
    
    return 0;
}
