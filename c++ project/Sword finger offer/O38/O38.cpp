#include <bits/stdc++.h>

using namespace std;

/*class Solution {
private:
    vector<string> res;
    void backtrace(string s, string track, vector<bool> &visited){
        if (track.size() == s.size()){
            res.push_back(track);
        }
        for (int i = 0; i < s.size(); ++i){
            if (visited[i]){
                continue;
            }
            if (i > 0 && !visited[i - 1] && s[i - 1] == s[i]){
                continue;
            }
            visited[i] = true;
            track.push_back(s[i]);
            backtrace(s, track, visited);
            track.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<string> permutation(string s) {
        if (s.empty()){
            return res;
        }
        sort(s.begin(), s.end());
        vector<bool> visited(s.size(), false);
        string track;
        backtrace(s, track, visited);
        return res;
    }
};*/

class Solution {
    unordered_set<string> us;
    void backtrace(string s, int x){
        if (x == s.size() - 1){
            us.insert(s);
            return;
        }
        unordered_set<char> dic;
        for (int i = x; i < s.size(); ++i){
            if (dic.find(s[i]) != dic.end()){
                continue;
            }
            dic.insert(s[i]);
            swap(s[x], s[i]);
            backtrace(s, x + 1);
            swap(s[x], s[i]);
        }
    }
public:
    vector<string> permutation(string s) {
        backtrace(s, 0);
        return vector<string>(us.begin(), us.end());
    }
};

int main()
{
    auto res = Solution().permutation(string("aab"));
    for (auto n : res){
        cout << n << endl;
    }
    return 0;
}
