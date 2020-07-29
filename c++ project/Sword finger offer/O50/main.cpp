#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if (s == ""){
            return ' ';
        }
        unordered_map<char, int> mp;
        for (const auto &ch : s){
            ++mp[ch];
        }
        for (const auto &ch : s){
            if (mp[ch] == 1){
                return ch;
            }
        }
        return ' ';
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
