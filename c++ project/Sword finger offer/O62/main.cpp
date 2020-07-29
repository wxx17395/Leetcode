#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }

private:
    int f(int n, int m){
        if (n == 1){
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
};

int main() {
    cout << Solution().lastRemaining(5,3) << endl;
    return 0;
}
