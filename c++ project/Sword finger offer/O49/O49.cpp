#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        int n2, n3, n5;
        for (int i = 1; i < n; ++i){
            n2 = dp[a] * 2;
            n3 = dp[b] * 3;
            n5 = dp[c] * 5;
            dp[i] = min(n2, min(n3, n5));
            if (dp[i] == n2) ++a;
            if (dp[i] == n3) ++b;
            if (dp[i] == n5) ++c;
        }
        return dp[n - 1];
    }
};

int main()
{
    
    return 0;
}
