#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dirs[4][2] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0, ni, nj;
        int k = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int x = 0; x < n * m; ++x){
            visited[i][j] = true;
            res.push_back(matrix[i][j]);
            ni = i + dirs[k][0];
            nj = j + dirs[k][1];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj]){
                k = (k + 1) % 4;
                ni = i + dirs[k][0];
                nj = j + dirs[k][1];
            }
            i = ni;
            j = nj;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}
