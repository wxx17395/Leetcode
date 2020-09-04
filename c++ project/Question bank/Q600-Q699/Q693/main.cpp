#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a = n & 1;
        n >>= 1;
        while (n != 0){
            if (a ^ (n & 1) == 0){
                return false;
            }
            a = n & 1;
            n >>= 1;
        }
        return true;
    }
};

int main() {

    cout << Solution().hasAlternatingBits(5);
    return 0;
}
