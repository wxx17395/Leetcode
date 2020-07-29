#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1){
            return false;
        }
        int n = sqrt(num), sum = 0;
        for (int i = n; i > 1; --i){
            if (num % i == 0){
                sum = sum + i + (num / i);
            }
        }
        return (sum + 1) == num;
    }
};

int main() {
    cout << Solution().checkPerfectNumber(1) << endl;
    return 0;
}
