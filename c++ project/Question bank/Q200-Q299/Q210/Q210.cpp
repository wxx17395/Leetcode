#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> in(numCourses, 0), res;
        for (auto n : prerequisites){
            ++in[n[0]];
            edges[n[1]].push_back(n[0]);
        }
        queue<int> q;
        for (int i = 0; i < in.size(); ++i){
            if (in[i] == 0){
                q.push(i);
            }
        }
        while (q.size()){
            for (auto n : edges[q.front()]){
                --in[n];
                if (in[n] == 0){
                    q.push(n);
                }
            }
            res.push_back(q.front());
            q.pop();
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};

int main()
{
    vector<vector<int>> a{{0, 1}};
    Solution().findOrder(2, a);    
    return 0;
}
