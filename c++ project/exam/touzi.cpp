#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.second / a.first) < (b.second / b.first);
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<pair<int, int>> zhongcan(n);
    vector<pair<int, int>> wancan(m);
    int res = INT_MAX;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        zhongcan[i] = make_pair(a, b);
        if (b >= t) res = min(res, a);
    }
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        wancan[i] = make_pair(a, b);
        if (b >= t) res = min(res, a);
    }
    sort(zhongcan.begin(), zhongcan.end(), cmp);
    sort(wancan.begin(), wancan.end(), cmp);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (zhongcan[i].second + zhongcan[j].second >= t){
                res = min(res, zhongcan[i].first + wancan[j].first);
            }
        }
    }
    cout << (res == INT_MAX ? -1 : res) << endl;
    system("pause");
    return 0;
}
