#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        unordered_map<int,int> mp;
        int k = 2, b = n;
        while (b >= k){
            int count = 0;
            while (b % k == 0){
                ++count;
                b = b / k;
            }
            if (count > 0) mp[k] = count;
            ++k;
        }
        int res = 0;
        for (auto p : mp){
            res += (p.first) * p.second;
        }
        return res;
    }
};

int main() {
    int a;
    while (cin >> a){
        cout << Solution().minSteps(a) << endl;
    }
    return 0;
}
