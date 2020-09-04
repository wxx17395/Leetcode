#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m < n){
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};

int main()
{
    cout << Solution().rangeBitwiseAnd(2147483646,2147483647) << endl;
    return 0;
}
