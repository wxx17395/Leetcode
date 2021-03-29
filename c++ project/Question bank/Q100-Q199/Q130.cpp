#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
    void dfs(vector<vector<char>>& board, int i, int j){
        if (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O'){
            board[i][j] = '-';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        } 
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i){
            dfs(board, i, m - 1);
            dfs(board, i, 0);
        }
        for (int i = 1; i < m - 1; ++i){
            dfs(board, 0 , i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (board[i][j] == '-'){
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> board{{'X', 'O', 'X', 'X'}, {'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X'}};
    Solution().solve(board);
    return 0;
}
