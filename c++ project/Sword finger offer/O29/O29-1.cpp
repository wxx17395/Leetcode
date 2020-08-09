#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int dirs[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        int m = matrix.size(), n = matrix.begin()->size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res(m * n);
        int i = 0, j = 0, ni, nj;
        int dirinedx = 0;
        for (int k = 0; k < m * n; ++k){
            res[k] = matrix[i][j];
            visited[i][j] = true;
            ni = i + dirs[dirinedx][0];
            nj = j + dirs[dirinedx][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj]){
                dirinedx = (dirinedx + 1) % 4;
            }
            i += dirs[dirinedx][0];
            j += dirs[dirinedx][1];
        }
        return res;
    }
};

int main()
{
    cout << 1 << endl;
    return 0;
}
