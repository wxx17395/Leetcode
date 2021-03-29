#include <bits/stdc++.h>
using namespace std;

/*class Solution {
private:
    bool check(string s){
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while (i < j){
            if (s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int l = words.size();
        string s;
        for (int i = 0; i < l; ++i){
            for (int j = 0; j < l; ++j){
                if (i == j ) continue;
                s = words[i] + words[j];
                if (check(s)){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};*/

class Solution {
private:
    vector<string> wordsRec;
    unordered_map<string, int> indices;
    int findWord(string s, int left, int right){
        auto iter = indices.find(s.substr(left, right - left + 1));
        return iter == indices.end() ? -1 : iter->second;
    }
    bool isPalindrome(string s, int left, int right){
        int len = right - left + 1;
        for (int i = 0; i < len / 2; ++i){
            if (s[left + i] != s[right - i]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        for (auto word : words){
            wordsRec.push_back(word);
            reverse(wordsRec.back().begin(), wordsRec.back().end());
        }
        for (int i = 0; i < n; ++i){
            indices[wordsRec[i]] = i;
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i){
            int m = words[i].size();
            if (!m) continue;
            string wordView(words[i]);
            for (int j = 0; j <= m; ++j){
                if (isPalindrome(wordView, j, m - 1)){
                    int left_id = findWord(wordView, 0, j - 1);
                    if (left_id != -1 && left_id != i){
                        res.push_back({i, left_id});
                    }
                }
                if (j && isPalindrome(wordView, 0, j - 1)){
                    int right_id = findWord(wordView, j, m - 1);
                    if (right_id != -1 && right_id != i){
                        res.push_back({right_id, i});
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}
