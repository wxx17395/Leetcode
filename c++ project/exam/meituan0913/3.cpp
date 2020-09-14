#include <bits/stdc++.h>
using namespace std;

int n, k, d;

int res = 0;
const int mod = 998244353;

void backtrace(int target, bool flag){
    if (target == 0){
        if (flag){
            res = (res + 1) % mod;
        }
        return;
    }
    if (target < 0){
        return;
    }
    for (int i = 1; i <= k; ++i){
        if (i >= d){
            backtrace(target - i, true);
        } else {
            backtrace(target - i, flag);
        }
    }
    return;
}

int main()
{
    cin >> n >> k >> d;
    backtrace(n, false);
    cout << res << endl;
    return 0;
}