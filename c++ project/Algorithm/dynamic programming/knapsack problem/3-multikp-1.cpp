#include <bits/stdc++.h>
using namespace std;

/*
f[i]表示体积不大于i的情况下，总价值最大是多少

result = f[m]
*/

const int N = 1010;

int n, m;
//全局变量被定义到堆中，被默认初始化为0
//局部变量被定义到栈中，初始值为任意
int f[N];
int v[N], w[N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = m; j >= v[i]; --j){
            for (int k = 1; k <= s[i] && k * v[i] <= j; ++k){
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
