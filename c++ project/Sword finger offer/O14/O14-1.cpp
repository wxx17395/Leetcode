#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3){
            return n - 1;
        }
        int a = n / 3, b = n % 3, res;
        res = pow(3, a);
        if (b == 1) {res = res / 3 * 4;}
        if (b == 2) {res = res * 2;}
        return res;
    }
};

int main()
{
    
    return 0;
}
