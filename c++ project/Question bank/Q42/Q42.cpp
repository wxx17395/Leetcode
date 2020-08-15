#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int func(vector<int>& height, int l, int r){
        int res= height[l] * (r - l - 1);
        for (int i = l + 1; i < r; ++i){
            res -= height[i];
        }
        return res;
    }
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;
        int tmp;
        for (int i = 0; i < height.size(); ++i){
            tmp = 0;
            while (!s.empty() && height[s.top()] <= height[i]){
                tmp = max(tmp, func(height, s.top(), i));
                if (height[s.top()] < height[i]){
                    s.pop();
                } else {
                    break;
                }
            }
            res += tmp;
            s.push(i);
        }
        return res;
    }
};

int main()
{
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(nums) << endl;
    return 0;
}
