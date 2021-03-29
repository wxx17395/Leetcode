#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        int dif = 'A' - 'a';
        for (auto &c : str){
            if ('A' <= c && c <= 'Z'){
                c = char(int(c) - dif);
            }
        }
        return str;
    }
};

int main() {
    cout << Solution().toLowerCase("JEasd") << endl;
    string S = "AsD";
    return 0;
}
