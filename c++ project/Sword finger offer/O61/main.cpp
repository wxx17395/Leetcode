#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        stack<int> s;
        int zero = 0;
        for (const auto &c : nums){
            if (c == 0){
                ++zero;
            }else if (s.empty() || s.top() == c - 1){
                s.push(c);
            }else{
                while (zero > 0 && s.top() != c - 1){
                    s.push(s.top() + 1);
                    --zero;
                }
                if (zero == 0 && s.top() != c - 1) return false;
                s.push(c);
            }
        }
        return (s.size() + zero) == 5 ? true : false;
    }
};

int main() {
    vector<int> nums{0,0,1,2,6};
    cout << Solution().isStraight(nums) << endl;
    return 0;
}
