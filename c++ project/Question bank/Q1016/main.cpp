#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 1; i <= N; ++i){
            bitset<20> bitstr(i);
            string tmp = bitstr.to_string();
            tmp.erase(0, tmp.find_first_of('1'));
            if (S.find(tmp) == S.npos){
                return  false;
            }
        }
        return true;
    }
};

int main() {
    string s{"0110"};
    cout << Solution().queryString(s, 4) << endl;
    return 0;
}
