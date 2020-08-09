#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long n2 = n;
        if (n < 0){
            x = 1 / x;
            n2 = -n2;
        }
        double res = 1;
        while (n2 > 0){
            if (n2 & 1){
                res *= x;
            }
            x *= x;
            n2 >>= 1;
        }
        return res;
    }
};

int main()
{
    cout << Solution().myPow(2, -2) << endl;
    return 0;
}
