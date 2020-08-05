#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int i, int j, int k){
        while (i > 0){
            k -= i % 10;
            i /= 10;
        }
        while (j > 0){
            k -= j % 10;
            j /= 10;
        }
        return k >= 0;
    }
    int count = 0;
    void dfs(int i, int j, int k, vector<vector<bool>> &visited, int m, int n){
        if (!check(i, j, k)){
            return;
        }
        ++count;
        visited[i][j] = true;
        if (i + 1 < m && !visited[i + 1][j]){
            dfs(i + 1, j, k, visited, m, n);
        }
        if (j + 1 < n && !visited[i][j + 1]){
            dfs(i, j + 1, k, visited, m, n);
        }
    }
public:
    int movingCount(int m, int n, int k) {
        int i = 0, j = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        dfs(0, 0, k, visited, m, n);
        return count;
    }
};

int main()
{
    
    return 0;
}
