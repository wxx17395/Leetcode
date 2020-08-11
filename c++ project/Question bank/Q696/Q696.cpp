#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int l = 0,r = 1;
        int next, cur = s[0];
        int res = 0;
        while (r < n){
            while (r < n && s[r] == cur){
                ++r;
            }
            if (r >= n) {
                break;
            }
            cur = s[r];
            int length = r - l;
            next = r;
            while (r < n && length > 0 && s[r] == cur){
                ++res;
                --length;
                ++r;
            }
            l = next;
            next = r;
        }
        return res;
    }
};

int main()
{
    cout << Solution().countBinarySubstrings(string("00110")) << endl;
    return 0;
}
