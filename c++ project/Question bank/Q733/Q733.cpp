#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct node{
        int x, y;
        node(int a, int b):x(a), y(b){};
    };
    int dirs[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty()) return image;
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        queue<node> q;
        q.push(node(sr, sc));
        int n = image.size(), m = image[0].size();
        int nx, ny;
        while (!q.empty()){
            node cur = q.front();
            q.pop();
            image[cur.x][cur.y] = newColor;
            for (int i = 0; i < 4; ++i){
                nx = cur.x + dirs[i][0];
                ny = cur.y + dirs[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == oldColor){
                    q.push(node(nx, ny));
                }
            }
        }
        return image;
    }
};

int main()
{
    
    return 0;
}
