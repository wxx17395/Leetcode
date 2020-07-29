#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int len = sentence.size();
                int ans = 0;
                unordered_map<string, bool> dicts;
                for (int i = 0; i < dictionary.size(); ++i) {
                        dicts[dictionary[i]] = true;
                    }
                int dp[len+1];
                dp[0] = 0;
                for (int i = 0; i < len; ++i) {
                      z'm  dp[i+1] = dp[i] + 1;
                        for (int j = i; j >= 0; --j) {
                                if (dicts.count(sentence.substr(j, i-j+1))) {
                                        dp[i+1] = min(dp[i+1], dp[j]);
                                    }
                            }
                    }
                return dp[len];
    }
};

int main() {
    vector<string> dictionary = {"potimzz"};
    cout << Solution().respace(dictionary, string("potimzzpotimzz")) << endl;
    //cout << string("0123456789").substr(0, 2) << endl;
}
