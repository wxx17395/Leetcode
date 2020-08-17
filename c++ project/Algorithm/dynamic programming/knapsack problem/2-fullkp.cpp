#include <bits/stdc++.h>
using namespace std;

/*
f[i]表示体积不大于i的情况下，最大价值是多少；
result = f[m];
*/

const int N = 1010;

int n, m;
//全局变量被定义到堆中，被默认初始化为0
//局部变量被定义到栈中，初始值为任意
int f[N];
int v[N], w[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; ++i){
        // f[j - v[i]]包含了可能使用第i个物品
        for (int j = v[i]; j >= m; ++j){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
