#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dirs[4][2] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    string tostr(int n, int m){
        string s = "[";
        s += to_string(n) + ',' + to_string(m) + ']';
        return s;
    }
public:
    void spiralOrder(int n, int m) {
        int i = 0, j = 0, ni, nj;
        int k = 0;
        string res = "[";
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int x = 1; x < n * m; ++x){
            if (((x % 10) == 7) && ((x / 10) % 2 == 1)){
                res += tostr(i, j) + ',';
            }
            visited[i][j] = true;
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
        res.pop_back();
        res += "]";
        cout << res << endl;
        return;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution().spiralOrder(m, n);
    return 0;
}
