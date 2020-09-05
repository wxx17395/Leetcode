#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T){
        int N;
        cin >> N;
        int x = 0, y = 0;
        int a, b;
        while(N){
            cin >> a >> b;
            --N;
            if (b == -1){
                continue;
            }
            if (a == 0){
                ++y;
            } else if (a == 1){
                --y;
            } else if (a == 2){
                --x;
            } else if (a == 3){
                ++x;
            }
        }
        cout << abs(x) + abs(y) << endl;
        --T;
    }
    return 0;
}
