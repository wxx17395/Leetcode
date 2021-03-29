#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()){
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        bool firstCol = false, firstLine = false;
        for (int i = 0; i < m; ++i){
            if (!matrix[i][0]){
                firstCol = true;
            }
        }
        for (int i = 0; i < n; ++i){
            if (!matrix[0][i]){
                firstLine = true;
            }
        }
        for (int i = 1 ; i < m ; ++i){
            for (int j = 1; j < n; ++j){
                if (!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1 ; i < m ; ++i){
            for (int j = 1; j < n; ++j){
                if (!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstLine){
            for (int i = 0; i < n; ++i){
                matrix[0][i] = 0;
            }
        }
        if (firstCol){
            for (int i = 0; i < m; ++i){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};

int main()
{
    
    return 0;
}
