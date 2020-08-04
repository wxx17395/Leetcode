#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()){
            return 0;
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int result = n;
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
        }        
        for (int i = n - 1; i > -1; --i){
            for (int j = i + 1; j < n; ++j){
                if (s[i] == s[j]){
                    dp[i][j] = (j - i == 1) ? true : dp[i + 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
                if (dp[i][j]){
                    ++result;
                }
                
                
            }
        }
        return result;
    }
};

int main()
{
    string s;
    while(cin >> s){
        cout << Solution().countSubstrings(s) << endl;
    }
    return 0;
}
