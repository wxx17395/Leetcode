#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;
        int tmp;
        for (int i = 0; i < height.size(); ++i){
            while (!s.empty() && height[s.top()] < height[i]){
                int top = s.top();
                s.pop();
                if (s.empty()){
                    break;
                }
                int distance = i - s.top() - 1;
                int bounded_height = min(height[i], height[s.top()]) - height[top];
                res += distance * bounded_height;
            }
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
