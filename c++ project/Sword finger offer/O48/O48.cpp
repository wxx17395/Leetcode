#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int i = -1, j = 0;
        unordered_map<char, int> mp;
        int res = 0;
        while (j < n){
            if (mp.find(s[j]) != mp.end()){
                i = max(mp[s[j]], i);
            }
            mp[s[j]] = j;
            res = max(res, j - i);
            ++j;
        }
        return res;
    }
};

int main()
{
    cout << Solution().lengthOfLongestSubstring(string("abba")) << endl;
    return 0;
}
