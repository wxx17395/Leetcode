#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*int cost = INT_MAX, res = 0;
        for (auto p : prices){
            cost = min(cost, p);
            res = max(res, p - cost);
        }
        return res;*/
        if (prices.empty()) return 0;
        int minprice = prices[0], n = prices.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++){
            minprice = min(prices[i], minprice);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
