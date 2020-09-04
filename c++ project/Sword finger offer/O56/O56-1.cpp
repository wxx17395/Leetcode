#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums){
            sum ^= n;
        }
        int div = 1;
        while ((div & sum) == 0){
            div <<= 1;
        }
        int a = 0, b = 0;
        for (auto n : nums){
            if (div & n){
                a ^= n;
            }else{
                b ^= n;
            }
        }
        return vector<int>{a, b};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
