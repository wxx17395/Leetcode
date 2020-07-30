#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1){
            return x;
        }
        if (x == -1){
            return n & 1 ? -1 : 1;
        }
        long m = n;
        if (n < 0){
            x = 1 / x;
            m = -m;
        }
        double result = 1;
        while ( m > 0){
            if (m & 1){
                result = result * x;
            }
            m >>= 1;
            x = x * x;
        }
        return result;
    }
};

int main()
{
    
    return 0;
}
