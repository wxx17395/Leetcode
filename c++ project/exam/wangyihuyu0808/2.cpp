#include <bits/stdc++.h>

using namespace std;

int main()
{
    long a;
    cin >> a;
    int res = 0;
    while (a > 0){
        if (a % 8 == 7){
            res++;
        }
        a /= 8;
    }
    cout << res << endl;
    return 0;
}
