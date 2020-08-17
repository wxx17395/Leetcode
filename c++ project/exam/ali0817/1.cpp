#include <bits/stdc++.h>
using namespace std;

string tostr(const vector<int> &num){
    ostringstream s;
    for (auto n : num){
        s << n;
    }
    return s.str();
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(n, vector<int>(k));
    int tmp, a, flag = -1, res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i){
        for (int j = 1; j < k; ++j){
            cin >> nums[i][j];
        }
    }
    
    cout << res << endl;
    return 0;
}
