#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> color;
    bool valid;
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       valid = true;
       color.assign(n, 0);
       for (int i = 0; i < n && valid; ++i){
           if (color[i] == 0){
               dfs(i,1,graph);
           }
       }
       return valid;
    }

private:
    void dfs(int node, int c, const vector<vector<int>>& graph){
        color[node] = c;
        int cNext = (c == 1 ? 2 : 1);
        for (int next : graph[node]){
            if (color[next] == 0){
                dfs(next, cNext, graph);
                if (!valid){
                    return;
                }
            } else if (color[next] != cNext){
                valid = false;
                return;
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
