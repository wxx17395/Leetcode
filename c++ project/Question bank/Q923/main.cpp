#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    int C(long n, long m) {
        if (m == 0) return 1;
        if (m == 1) return n;
        if (m == 2) return (n * (n - 1) / 2) % M;
        return (n * (n - 1) * (n - 2) / 6) % M;
    }
    set<vector<int> > twoSum(map<int, int>& m, int target, int low) {
        set<vector<int> > res;
        int mid = target / 2;
        for (auto& p : m) {
            if (p.first < low || p.second == 0) continue;
            if (p.first > mid) break;
            if ((target == 2 * p.first && p.second >= 2) ||
                (target != 2 * p.first && m.count(target - p.first) > 0)) {
                res.insert({p.first, target - p.first});
            }
        }
        return res;
    }
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> m;
        for (auto x : A) ++m[x];
        set<vector<int> > s;
        int min_val = target / 3;
        for (auto& p : m) {
            if (p.first > min_val) break;
            --p.second;
            auto t = twoSum(m, target - p.first, p.first);
            for (auto x : t) {
                x.insert(x.begin(), p.first);
                s.insert(x);
            }
            ++p.second;
        }
        int res = 0;
        for (auto& v : s) {
            map<int, int> t;
            for (auto x : v) ++t[x];
            int n = 1;
            for (auto p : t) {
                n *= C(m[p.first], p.second);
            }
            res += n;
        }
        return res;
    }
};

int main() {
    vector<int> A{1,1,2,2,2,2};
    cout << Solution().threeSumMulti(A, 5) << endl;
    return 0;
}
