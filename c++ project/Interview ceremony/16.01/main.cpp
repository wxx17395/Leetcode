#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        int &a = numbers[0], &b = numbers[1];
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return numbers;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
