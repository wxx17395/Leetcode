#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<int> used;
    int n, k, count = 0;
    int factorial = 1;
    stringstream s;
    void helper(vector<int> &tmp) {
        int l = tmp.size();
        string res;
        if (l == n){
            copy(tmp.begin(), tmp.end(), ostream_iterator<int>(s, ""));
            return;
        }
        int groupNum = factorial / (n - l);
        factorial = groupNum;
        for (int i = 1; i <= n; ++i){
            if (used.find(i) != used.end()){
                continue;
            }
            if (k > groupNum){
                k = k - groupNum;
                continue;
            }
            tmp.push_back(i);
            used.insert(i);
            helper(tmp);
        }
        return;
    };
public:
    string getPermutation(int n, int k) {
        this->n = n;
        this->k = k;
        for (int i = 1; i <= n; ++i){
            factorial *= i;
        }
        vector<int> tmp;
        helper(tmp);
        return s.str();
    }
};

int main()
{
    stringstream s;
    vector<int> nums(5);
    iota(nums.begin(), nums.end(), 1);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(s, ";"));
    cout << s.str() << endl;;
    cout << s.str().size() << endl;
}
