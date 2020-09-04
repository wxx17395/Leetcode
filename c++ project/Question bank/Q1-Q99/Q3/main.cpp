#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int i = 0, j = 0, res = INT_MIN, n = s.size();
        unordered_set<char> dict;
        while (j < n){
            if (dict.count(s[j]) > 0){
                while (s[i] != s[j]){
                    dict.erase(s[i++]);
                }
                ++i;
            } else{
                dict.insert(s[j]);
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring(string("abbbbbbba"));
    return 0;
}
