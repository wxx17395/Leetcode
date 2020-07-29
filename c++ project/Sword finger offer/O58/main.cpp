#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords_1(string s) {
        string res, cur;
        bool flag = false;
        s += ' ';
        for (auto ch : s){
            if (ch != ' '){
                flag = true;
                cur += ch;
            }else{
                if (flag == false) continue;
                res = cur + ' ' + res;
                cur.clear();
                flag = false;
            }
        }
        return res;
    }

    string reverseWords(string s) {
        string res;
        int begin = s.find_first_not_of(' '), end = s.find_last_not_of(' ') - s.find_first_not_of(' ') + 1;
        if (begin == -1) return "";
        s = s.substr(begin, end);
        int n = s.size(), l = n - 1 , r = n -1;
        while (l >= 0){
            r = l;
            while (l >= 0 && s[l] != ' ') --l;
            res += s.substr(l + 1, r - l);
            res += ' ';
            while (l >= 0 && s[l] == ' ') --l;
            r = l;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }

    string reverseLeftWords(string s, int n) {
        string res;
        int m = s.size();
        res += s.substr(n);
        res += s.substr(0,n);
        return res;
    }
};

int main() {
    Solution s;
    //cout << s.reverseWords("the sky is blue") << endl;
    cout << s.reverseWords("   ") << endl;
    cout << s.reverseWords("a good   example") << endl;
    cout << s.reverseWords("test") << endl;
    return 0;
}
