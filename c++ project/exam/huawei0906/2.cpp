#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T){
        set<vector<int>> st;
        int n;
        cin >> n;
        bool flag = false;
        while (n){
            vector<int> cur(6);
            for (int i = 0; i < 6; ++i){
                cin >> cur[i];
            }
            sort(cur.begin(), cur.end());
            if (st.find(cur) != st.end()){
                flag = true;
                cout << "YES" << endl;
                break;
            }
            st.insert(cur);
            --n;
        }
        if (!flag){
            cout << "NO" << endl;
        }
        --T;
    }
    return 0;
}
