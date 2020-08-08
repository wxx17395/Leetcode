#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0, pre = nums[0];
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == pre){
                ++n;
            }else{
                --n;
                if (n == 0){
                    pre = nums[i];
                    ++n;
                }
            }
        }
        return pre;
    }
};

int main()
{
    
    return 0;
}
