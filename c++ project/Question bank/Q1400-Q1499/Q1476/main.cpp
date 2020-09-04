#include <bits/stdc++.h>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>>& myrectangle;
    vector<vector<int>> history;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle):myrectangle(rectangle) {
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = history.size() - 1; i >= 0; --i){
            if (history[i][0] <= row && history[i][2] >= row && history[i][1] <= col && history[i][3] >= col){
                return history[i][4];
            }
        }
        return myrectangle[row][col];
    }
};

int main() {
    return 0;
}
