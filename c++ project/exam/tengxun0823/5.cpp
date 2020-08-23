#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s, int cl, int cr) {
    if (cr < cl){
        return 0;
    }
    if (cr == cl){
        return 1;
    }
    int n = cr - cl + 1;
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    int maxl, maxr;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            }
            else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            }
            else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                maxl = i;
                maxr = l + 1;
            }
        }
    }
    return 1 + longestPalindrome(s, cl, maxl - 1) + longestPalindrome(s, maxr + 1, cr);
}

int main()
{
    string s;
    cin >> s;
    int l, r, k;
    cin >> k;
    ostringstream os;
    for (int i = 0; i < k; ++i){
        cin >> l >> r;
        os << longestPalindrome(s, l - 1, r - 1) << endl;
    }
    cout << os.str();
    return 0;
}
