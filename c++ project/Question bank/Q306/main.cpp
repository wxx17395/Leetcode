#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(string num, int i, int j, int k){
        if (num[i] == '0' && j - i != 1) return false;
        if (num[j] == '0' && k - j != 1) return false;
        string s1 = num.substr(i, j - i);
        string s2 = num.substr(j, k - j);
        string sum = add(s1, s2);
        int m = num.size(), n = sum.size();
        if (n + k - 1 >= m) return false;
        for(int p = k; p < k + n; ++p){
            if (num[p] != sum[p - k]){
                return false;
            }
        }
        if (n + k - 1 == m - 1) return true;
        return dfs(num, j, k, k + n);

    }

    string add(string s1, string s2){
        int m = s1.size() - 1, n = s2.size() - 1;
        int flag = 0;
        string res;
        while (m >= 0 || n >= 0 || flag == 1){
            int a = m >= 0 ? s1[m--] - '0' : 0;
            int b = n >= 0 ? s2[n--] - '0' : 0;
            res += (a + b + flag) % 10 + '0';
            flag = (a + b + flag) / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    bool isAdditiveNumber(string num) {
        int i = 0, n = num.size();
        for (int j = i + 1; j < n ; ++j){
            for (int k = j + 1; k < n; ++k){
                if (dfs(num, i, j, k)) return true;
            }
        }
        return false;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
