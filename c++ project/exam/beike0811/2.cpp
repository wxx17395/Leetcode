#include <bits/stdc++.h>

using namespace std;

int mod = (1e9) + 7;
vector<vector<int>> dp(1001, vector<int>(1001));

struct graph{
    int x, y;
    int val;
};

int findroot(vector<int> &parent, int x){
    while (parent[x] != -1){
        x = parent[x];
    }
    return x;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<graph> nums(m);
    int i, j;
    for (j = 0; j < 1001; ++j){
        dp[j][j] = 1;
        for (i = j + 1; i < 1001; ++i){
            if (j == 0){
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
    int a, b;
    for (i = 0; i < m; ++i){
        cin >> nums[i].x >> nums[i].y;
        cin >> a >> b;
        nums[i].val = dp[a][b];
    }
    sort(nums.begin(), nums.end(), [](graph a, graph b) {return a.val > b.val;});
    int res = 0, count = 0;
    vector<int> parent(n + 1, -1);
    for (auto v : nums){
        a = findroot(parent, v.x);
        b = findroot(parent, v.y);
        if (a != b){
            parent[a] = b;
        }
        res = (res + v.val) % mod;
        ++count;
        if (count == n - 1){
            break;
        }
    }
    if (count == n - 1){
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
