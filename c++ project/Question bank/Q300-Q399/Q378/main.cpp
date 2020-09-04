#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 归并排序
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        for (int i = 0; i < n ; ++i){
            q.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; ++i){
            point cur = q.top();
            q.pop();
            if (cur.y != n - 1){
                q.emplace(matrix[cur.x][cur.y + 1], cur.x, cur.y + 1);
            }
        }
        return q.top().val;
    }

private:
    struct point{
        int val, x, y;
        point(int val, int x, int y):val(val), x(x), y(y){};
        bool operator < (const point &a) const {
            return this->val > a.val;
        }
    };
    priority_queue<point> q;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
