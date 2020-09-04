#include <bits/stdc++.h>
using namespace std;

/*
f[i][j]表示只看前i个物品，总体积为j的情况下，总价值最大是多少

result = max(f[n][0 - v])

f[i][j] = max{1, 2}:
    1. 不选第i个物品，  f[i][j] = f[i - 1][j];
    2. 选第i个物品，    f[i][j] = f[i - 1][j - v[i]] + v[i];
f[0][0] = 0;
*/

const int N = 1010;

int n, m;
//全局变量被定义到堆中，被默认初始化为0
//局部变量被定义到栈中，初始值为任意
int f[N][N];
int v[N], w[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            f[i][j] = f[i - 1][j];
            if (j >= v[i]){
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= m; ++i){
        res = max(res, f[n][i]);
    }
    cout << res << endl;
    return 0;
}
