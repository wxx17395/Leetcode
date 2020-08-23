#include <bits/stdc++.h>
using namespace std;

int n, k;
int ret = 0;
vector<int> cur;

void backtrace(int l, int r){
    int mid = l + ceil(float(r - l) / 2);
    if (r - mid <= 1 && mid - l <= 1){
        int res = mid;
        int m = cur.size() - k;
        for (int i = 0; i < m; ++i){
            res += cur[i];
            cout << cur[i] << endl;
        }
        ret = max(ret, res);
        return;
    }
    cur.push_back(mid);
    if (r - mid > 1){
        backtrace(mid + 1, r);
    }
    if (mid - l > 1){
        backtrace(l, mid - 1);
    }
    cur.pop_back();
}

int main()
{
    cin >> n >> k;
    backtrace(1, n);
    cout << ret << endl;
    return 0;
}