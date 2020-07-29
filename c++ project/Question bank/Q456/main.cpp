#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int m = nums.size();
        if (m < 3) return false;
        stack<int> s;
        int minlist[m];
        minlist[0] = 0;
        for (int i = 1; i < m; ++i){
            minlist[i] = min(minlist[i - 1], nums[i]);
        }
        for (int j = m - 1; j > -1; --j){
            if (nums[j] > minlist[j]){
                while (!s.empty() && s.top() <= minlist[j]){
                    s.pop();
                }
                if (!s.empty() && s.top() < nums[j]){
                    return true;
                }
                s.push(nums[j]);
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
