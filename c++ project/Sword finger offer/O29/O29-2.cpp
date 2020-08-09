#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int findBegin(int cycle, int n){
        int res = 1;
        for (int i = 1; i < cycle; ++i){
            int nn = n - (i - 1) * 2;
            int num = 4 * nn - 4;
            res += num;
        }
        return res;
    }

    int search(int x, int y, int n){
        int numOfCycle = min(n - x + 1, min(n - y + 1, min(x, y)));
        int cycleBegin = findBegin(numOfCycle, n);
        int dn = n - (numOfCycle - 1) * 2;
        int res = 0;
        if (x == numOfCycle){
            res = cycleBegin + (y - numOfCycle);
        } else if (y == n - numOfCycle + 1){
            res = cycleBegin + (x - numOfCycle) + dn - 1;
        } else if (x == n - numOfCycle + 1){
            res = cycleBegin + abs(y - (n - numOfCycle + 1)) + 2 * (dn - 1);
        } else if (y == numOfCycle){
            res = cycleBegin + abs(x - (n - numOfCycle + 1)) + 3 * (dn - 1);
        }
        return res;
    }

public:
    void spiralOrder(int n) {
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                cout << search(i, j, n) << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution().spiralOrder(4);
    return 0;
}
