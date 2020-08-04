#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board.begin()->size();
        vector<vector<int>> visited(n, vector<int>(m));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (board[i][j] == word[0] && dfs(board, visited, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int i, int j, int k){
        if (k == word.size() - 1){
            return true;
        }
        visited[i][j] = 1;
        for (int l = 0; l < 4; l ++){
            int ni = i + dirs[l][0], nj = j + dirs[l][1];
            if (ni > -1 && ni < n && nj > -1 && nj < m && !visited[ni][nj] && board[ni][nj] == word[k + 1] && dfs(board, visited, word, ni, nj, k + 1)){
                return true;
            }
        }
        visited[i][j] = 0;
        return false;
    }
};

int main()
{
    vector<vector<char>> board{{'a', 'b'}};
    cout << Solution().exist(board, string("ab")) << endl;
    return 0;
}
