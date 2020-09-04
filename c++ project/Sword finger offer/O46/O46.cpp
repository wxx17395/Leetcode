#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int res = 0, n;
    void backtrace(string s, int x){
        if (x == n){
            ++res;
            return;
        }
        backtrace(s, x + 1);
        if (x < n -1){
            if ((s[x] == '2' && s[x + 1] < '6') || (s[x] == '1')){
                backtrace(s, x + 2);
            }
            
        }
    }
public:
    int translateNum(int num) {
        string s = to_string(num);
        n = s.size();
        backtrace(s, 0);
        return res;
    }
};

int main()
{
    cout << Solution().translateNum(18580) << endl;
    return 0;
}
