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

struct Good{
    int v, w;
};

int main()
{
    vector<Good> goods;
    cin >> n >> m;
    int v, w, s;
    for (int i = 1; i <= n; ++i){
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2){
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if (s > 0){
            goods.push_back({v * s, w * s});
        }
    }
    for (auto good : goods){
        for (int j = m; j >= good.v; --j){
            f[j] = max(f[j], f[j - good.v] + good.w);
        }
    }
    cout << f[m] << endl;
    return 0;
}
