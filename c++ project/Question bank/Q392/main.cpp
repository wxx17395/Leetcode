#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i){
            dp[m][i] = m;
        }
        for (int i = m - 1; i >= 0; --i){
            for (int j = 0; j < 26; ++j){
                if (t[i] == j + 'a'){
                    dp[i][j] = i;
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (dp[add][s[i] - 'a'] == m) {
                return false;
            }
            add = dp[add][s[i] - 'a'] + 1;
        }
        return true;
    }

    /*bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty() && !s.empty()) return false;
        int i = 0, j = 0, m = s.size(), n = t.size();
        while (i < m && j < n){
            if (s[i] == t[j]){
                ++i;
            }
            ++j;
        }
        return i == m;
    }*/
};

int main() {
    string s = "abc", t = "ahbgdc";
    cout << Solution().isSubsequence(s, t);
    return 0;
}
