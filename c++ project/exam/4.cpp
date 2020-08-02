#include <bits/stdc++.h>
using namespace std;

int count = 0;

void recursion(vector<vector<int>> &grid, int i, int j){
    
}

int main()
{
    vector<vector<int>> grid(6, vector<int>(6));
    string s;
    for (int i = 0; i < 6; ++i){
        cin >> s;
        for (int j = 0; j < 6; ++j){
            if (s[j] == '#'){
                grid[i][j] == -1;
            }
        }
    }

    return 0;
}
