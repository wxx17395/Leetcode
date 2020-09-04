#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> edges;
    vector<int> indeg;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i){
            if (indeg[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()){
            ++visited;
            int c = q.front(); q.pop();
            for (auto v : edges[c]){
                --indeg[v];
                if (indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};

int main()
{
    vector<vector<int>> n{{1, 0}, {0,1}};
    cout << Solution().canFinish(2, n) << endl;
    return 0;
}
