#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> hashmap;
        int res = 0;
        for (auto &ch : chars){
            ++hashmap[ch];
        }
        unordered_map<char, int> chashmap;
        for (auto &s : words){
            chashmap.clear();
            bool isMatch = true;
            for (auto &c : s){
                ++chashmap[c];
            }
            for (char &c : s){
                if (hashmap[c] < chashmap[c]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch){
                res += s.size();
            }
        }
        return res;
    }
};

int main() {
    vector<string> words = {"cat","bt","hat","tree"};
    cout << Solution().countCharacters(words, "atach") << endl;
    return 0;
}
