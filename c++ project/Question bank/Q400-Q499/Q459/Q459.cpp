#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i){
            if (n % i != 0){
                continue;
            }
            bool match = true;
            for (int j = i; j < n; ++j){
                if (s[j] != s[j - i]){
                    match = false;
                    break;
                }
            }
            if (match){
                return true;
            }
        }
        return false;
    } 
};

int main()
{
    
    return 0;
}
