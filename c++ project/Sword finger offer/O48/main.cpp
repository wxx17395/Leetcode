#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;
//using std::unordered_map;

class Solution {
public:
    // 滑动窗口 + hash表
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0){
            return 0;
        }
        int l = -1, maxc = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < s.size(); r++){
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]], l);
            }
            mp[s[r]] = r;
            maxc = max(maxc, r - l);

        }
        return maxc;
    }
};

int main() {
    Solution s;
    int i = s.lengthOfLongestSubstring("abcabcbb");
    cout << i << endl;
    return 0;
}
