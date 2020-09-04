#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumbers(vector<int>& nums) {
        vector<int> bit(32);
        for (int i = 0; i < nums.size(); ++i){
            for (int j = 0; j < 32; ++j){
                bit[j] += ((nums[i] >> j) & 1);
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i){
            if (bit[i] % 3 == 1){
                res += (1 << i);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}
