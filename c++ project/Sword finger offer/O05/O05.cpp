#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i){
            if (s[i] == ' '){
                s 
                += "  ";
            }
        }
        int i = n - 1, j = s.size() - 1;
        while (i >= 0){
            if (s[i] != ' '){
                s[j--] = s[i--];
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                --i;
            }
        }
        return s;
    }
};

int main()
{
    string s;
    getline(cin, s);
    cout << Solution().replaceSpace(s) << endl;
    return 0;
}
