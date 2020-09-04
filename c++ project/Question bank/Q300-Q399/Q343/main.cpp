#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int a = 0;
        while (n > 4){
            n -= 3;
            ++a;
        }
        return pow(3, a) * n;
    }
};

int main()
{
    
    return 0;
}
