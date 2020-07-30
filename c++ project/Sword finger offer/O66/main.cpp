#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size(), cur = 1;
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i){
            cur *= a[i - 1];
            res[i] = cur;
        }
        cur = 1;
        for (int i = n - 2; i > -1; --i){
            cur *= a[i + 1];
            res[i] *= cur;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
