#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long digit = 1, start = 1, count = 9;
        while (n > count){
            n -= count;
            start *= 10;
            ++digit;
            count = 9 * start * digit; 
        }
        int num = start + (n - 1) / digit;
        return to_string(num)[(n - 1) % digit] - '0';
    }
};

int main()
{
    
    return 0;
}
