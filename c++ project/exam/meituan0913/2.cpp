#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> vec;
int res = 0;

int main()
{
    cin >> n >> m >> k;
    vec.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> vec[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (vec[i] >= k){
            ++cnt;
            if (cnt >= m){
                ++res;
            }
        } else {
            cnt = 0;
        }
    }
    cout << res << endl;
    return 0;
}
