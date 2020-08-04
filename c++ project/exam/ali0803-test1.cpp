#include <bits/stdc++.h>
using namespace std;

struct house{
    int first, second, used;
    house():used(0){};
};

bool cmp(house &a, house &b){
    return (a.second / a.first) > (b.second / b.first);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    vector<house> houses(m);
    for (int i = 0; i < n; ++i){
        cin >> coins[i];
    }
    for (int i = 0; i < m; ++i){
        cin >> houses[i].first >> houses[i].second;
    }
    sort(coins.begin(), coins.end());
    sort(houses.begin(), houses.end(), cmp);
    int res = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (houses[i].used == 1) continue;
            if (coins[i] >= houses[i].second){
                houses[i].used = 1;
                res += houses[i].first;
            }
        }
    }
    cout << res << endl;
    return 0;
}
