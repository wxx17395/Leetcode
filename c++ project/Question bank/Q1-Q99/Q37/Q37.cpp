#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> line_set;
    vector<vector<int>> col_set;
    vector<vector<int>> grid_set;

    bool backtrace(vector<vector<char>>& board, int i, int j){
        if (i == 9 && j == 0){
            return true;
        }
        int ni = (j == 8) ? i + 1 : i;
        int nj = (j + 1) % 9;
        int c = (i / 3) * 3 + (j / 3);
        if (isdigit(board[i][j])){
            return backtrace(board, ni, nj);
        }
        for (int k = 1; k <= 9; ++k){
            if (line_set[i][k] == 1){
                continue;
            }
            if (col_set[j][k] == 1){
                continue;
            }
            if (grid_set[c][k] == 1){
                continue;
            }
            board[i][j] = k + '0';
            //cout << i << ';' << j << ';' <<  board[i][j] << endl;
            line_set[i][k] = 1;
            col_set[j][k] = 1;
            grid_set[c][k] = 1;
            if (backtrace(board, ni, nj)){
                return true;
            }
            line_set[i][k] = 0;
            col_set[j][k] = 0;
            grid_set[c][k] = 0;
            board[i][j] = '.';
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        col_set.resize(9, vector<int>(10));
        line_set.resize(9, vector<int>(10));
        grid_set.resize(9, vector<int>(10));
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (isdigit(board[i][j])){
                    int k = board[i][j] - '0';
                    //cout << i << j << k << endl;
                    line_set[i][k] = 1;
                    col_set[j][k] = 1;
                    grid_set[(i / 3) * 3 + (j / 3)][k] = 1;
                }
            }
        }
        backtrace(board, 0, 0); 
        return;
    }
};


int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution().solveSudoku(board);

    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
