#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        long a = 0, b = 1, tmp;
        for (int i = 2; i <= n; ++i){
            tmp = (a + b) % (1000000007);
            a = b % (1000000007);
            b = tmp % (1000000007);
        }
        return b;
    }
};

int main()
{
    return 0;
}
