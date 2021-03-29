#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, int> smp, tmp;
    bool check(){
        for (const auto p : smp){
            if (tmp[p.first] < p.second){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        for (auto c : t){
            ++smp[c];
        }
        int i = 0, j = -1;
        int len = INT_MAX, ansl = -1;
        while (j < int(s.size())){
            if (smp.find(s[++j]) != smp.end()){
                ++tmp[s[j]];
            }
            while (check() && i <= j){
                if (j - i + 1 < len){
                    len = j - i + 1;
                    ansl = i;
                }
                if (smp.find(s[i]) != smp.end()){
                    --tmp[s[i]];
                }
                ++i;
            }
        }
        return ansl == -1 ? string() : s.substr(ansl, len);
    }
};

int main()
{
    cout << Solution().minWindow(string("ADOBECODEBANC"), string("ABC")) << endl;
    return 0;
}
