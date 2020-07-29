#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        auto t = (unsigned int)(a & b);
        while (b != 0){
            int c = t << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
