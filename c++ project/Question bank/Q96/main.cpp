#include <bits/stdc++.h>
using namespace std;

/*class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i){
            for (int j = 1; j <= i; ++j){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};*/

class Solution {
public:
    int numTrees(int n) {
        return partition(1, n);
    }

private:
    unordered_map<int, int> dict;
    int partition(int l, int r){
        if (dict.find(r - l) != dict.end()){
            return dict[r - l];
        }
        if (l > r){
            return 1;
        }
        int sum = 0;
        for (int i = l; i <= r; ++i){
            int left = partition(l, i - 1);
            int right = partition(i + 1, r);
            sum += left * right;
        }
        dict[r - l] = sum;
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
