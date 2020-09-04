#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = sqrt(area);
        int w = area / l;
        while (area % l != 0 || l < w){
            ++l;
        }
        return vector<int>{l, area/l};
    }
};

int main() {
    vector<int> nums = Solution().constructRectangle(2);
    return 0;
}
