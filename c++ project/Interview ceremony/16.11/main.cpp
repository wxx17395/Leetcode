#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0){
            return vector<int>();
        }
        if (shorter == longer){
            return vector<int>(1, shorter * k);
        }
        vector<int> res(k + 1);
        for(int i = 0; i <= k; ++i){
            res[i] = shorter * (k - i) + longer * i;
        }
        return res;
    }
};

int main() {
    Solution().divingBoard(1,2,3);
    return 0;
}
