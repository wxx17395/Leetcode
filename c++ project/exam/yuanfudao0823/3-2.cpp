#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int l = 1, r = n, mid = 0, res = 0;
    vector<int> vec;
    int pre;
    while (r - l > 1){
        pre = mid;
        mid = l + ceil(float(r - l) / 2);
        vec.push_back(mid);
        l = mid + 1;
    }
    if (l - pre > 2){
        vec.insert(vec.end() - 2, pre + 1);
    }
    int m = vec.size() - k;
    for (int i = 0; i < m; ++i){
        res += vec[i];
    }
    cout << res << endl;
    return 0;
}