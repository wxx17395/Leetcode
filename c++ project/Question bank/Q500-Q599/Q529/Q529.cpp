#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int dirs[8][2] {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        int i = click[0], j = click[1], ni, nj;
        if (board[i][j] == 'M'){
            board[i][j] = 'X';
            return board;
        } 
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<vector<int>> visited(n, vector<int>(m));
        visited[i][j] = 1;
        int count = 0;
        while (!q.empty()){
            tie(i, j) = q.front();
            q.pop();
            count = 0;
            for (int k = 0; k < 8; ++k){
                ni = i + dirs[k][0];
                nj = j + dirs[k][1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m){
                    continue;
                }
                if (board[ni][nj] == 'M'){
                    ++count;
                }            
            }
            if (count > 0){
                board[i][j] = count + '0';
            } else {
                board[i][j] = 'B';
                for (int k = 0; k < 8; ++k){
                    ni = i + dirs[k][0];
                    nj = j + dirs[k][1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] != 'E' || visited[ni][nj]){
                        continue;
                    }
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        return board;
    }
};

int main()
{
    
    return 0;
}
