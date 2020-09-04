#include <bits/stdc++.h>
using namespace std;


int main()
{
    string frame, brick;
    cin >> frame >> brick;
    int lf = frame.size(), lb = brick.size();
    vector<int> f(lf);
    vector<int> m(lb);
    int tmp = INT_MAX;
    for (int i = 0; i < lf; ++i){
        f[i] = frame[i] - '0';
        tmp = min(f[i], tmp);
    }
    for (int i = 0; i < lf; ++i){
        f[i] -= tmp;
    }
    

    return 0;
}
