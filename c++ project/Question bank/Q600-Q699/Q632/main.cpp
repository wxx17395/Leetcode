#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; ++i){
            for (const auto x : nums[i]){
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }    

        vector<int> freq(n);
        int inside = 0;
        int left = xMin, right = xMin - 1;
        int bestLeft = xMin, bestRight = xMax;

        while (right < xMax){
            ++right;
            if (indices.count(right)){
                for (const auto x : indices[right]){
                    ++freq[x];
                    if (freq[x] == 1){
                        ++inside;
                    }
                }
                while (inside == n) {
                    if (right - left < bestRight - bestLeft){
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.count(left)){
                        for (const auto x : indices[left]){
                            --freq[x];
                            if (freq[x] == 0){
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }
        return {bestLeft, bestRight};
    }
};

int main()
{
    
    return 0;
}
