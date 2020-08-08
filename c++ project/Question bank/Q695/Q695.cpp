#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int dirs[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<pair<int, int>> q;
        int res = 1;
        q.push(make_pair(x, y));
        int i, j, ni, nj;
        visited[x][y] = true;
        while (!q.empty()){
            tie(i, j) = q.front(); q.pop();
            for (int k = 0; k < 4; ++k){
                ni = i + dirs[k][0], nj = j + dirs[k][1];
                if (ni > -1 && ni < n && nj > -1 && nj < m && grid[ni][nj] == 1 && !visited[ni][nj]){
                    q.push(make_pair(ni, nj));
                    visited[ni][nj] = true;
                    ++res;
                }
            }
        }
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }
        int res = 0;
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 1 && !visited[i][j]){
                    res = max(res, bfs(grid, visited, i, j));
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout << Solution().maxAreaOfIsland(grid) << endl;
    return 0;
}
