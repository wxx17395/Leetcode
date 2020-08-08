#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        edges[i] = make_pair(a, b);
    }
    
}
