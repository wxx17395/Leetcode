#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix.begin()->size();
        int i = 0, j = m - 1;
        while (i < n && -1 < j)
        {
            int num = matrix[i][j];
            if (num < target){
                ++i;
            } else if (num > target){
                --j;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}
