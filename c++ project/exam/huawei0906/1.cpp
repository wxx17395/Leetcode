#include <bits/stdc++.h>
using namespace std;


int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    // 有一个字符串为空串
    if (n * m == 0) return n + m;

    // DP 数组
    int D[n + 1][m + 1];

    // 边界状态初始化
    for (int i = 0; i < n + 1; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
        D[0][j] = j;
    }

    // 计算所有 DP 值
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int left = D[i - 1][j] + 1;
            int down = D[i][j - 1] + 1;
            int left_down = D[i - 1][j - 1];
            if (word1[i - 1] != word2[j - 1]) left_down += 1;
            D[i][j] = min(left, min(down, left_down));

        }
    }
    return D[n][m];
}

int main()
{
    string s;
    getline(cin, s);
    int l = s.find_first_of(';');
    string src;
    for (int i = 0; i < l; ++i){
        if (s[i] == '.' || s[i] == '!'){
            src.push_back(',');
        } else {
            src.push_back(tolower(s[i]));
        }
    }
    string dst;
    for (int i = l + 1; i < s.size(); ++i){
        if (s[i] == '.' || s[i] == '!'){
            dst.push_back(',');
        } else {
            dst.push_back(tolower(s[i]));
        }
    }
    int cnt = 0;
    bool hasalnum = false;
    for (int i = 0; i < dst.size(); ++i){
        if (dst[i] == ' '){
            if (hasalnum){
                ++cnt;
                hasalnum = false;
            }
        } else if (dst[i] == ',' || dst[i] == '?'){
            ++cnt;
            if (hasalnum){
                ++cnt;
                hasalnum = false;
            }
        } else {
            hasalnum = true;
        }
    }
    if (hasalnum) ++cnt;
    int diff;
    cout << "(" << diff << "," << cnt << ")" << endl;
    return 0;
}
