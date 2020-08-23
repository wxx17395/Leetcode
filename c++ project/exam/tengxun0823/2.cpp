#include <bits/stdc++.h>
using namespace std;

string s;

struct cmp{
    bool operator() (int i, int j){
        while (i < s.size() && j < s.size()){
            if (s[i] < s[j]){
                return false;
            } else if (s[i] > s[j]){
                return true;
            } else {
                ++i; ++j;
            }
        }
        return true;
    }
};

int main()
{
    cin >> s;
    int k;
    cin >> k;
    priority_queue<int, vector<int>, cmp> q;
    for (int i = 0; i < s.size(); ++i){
        q.push(i);
    }
    set<string> st;
    while (!q.empty()){
        int x = q.top(); q.pop();
        for (int i = 1; i < s.size() - x + 1; ++i){
            if (st.size() == k - 1){
                cout << s.substr(x, i) << endl;
                return 0;
            }
            st.insert(s.substr(x, i));
        }
    }
    return 0;
}
