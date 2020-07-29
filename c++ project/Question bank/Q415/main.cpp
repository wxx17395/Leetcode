#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size() - 1, m = num2.size() - 1;
        string res;
        int flag = 0;
        while (n >= 0 || m >= 0){
            int a = n >= 0 ? num1[n--] - '0' : 0;
            int b = m >= 0 ? num2[m--] - '0' : 0;
            int sum = a + b;
            if (flag == 1) ++sum;
            int d = sum % 10;
            flag = sum / 10;
            res += char(d + '0');
        }
        /*while (n >= 0){
            int a = num1[n--] - '0';
            if (flag == 1) ++a;
            int d = a % 10;
            flag = a / 10;
            res += char(d + '0');
        }
        while (m >= 0){
            int a = num2[m--] - '0';
            if (flag == 1) ++a;
            int d = a % 10;
            flag = a / 10;
            res += char(d + '0');
        }*/
        if (flag) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    cout << Solution().addStrings(string("9"), string("99"));
    return 0;
}
