#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        for (int i = 2; i < A.size(); ++i){
            if (A[i] + A[i - 2] == 2 * A[i - 1]){
                dp[i] = dp[i - 1] + 1;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
