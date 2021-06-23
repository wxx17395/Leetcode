#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N--);

        int index = 0;
        while (N){
            if (index == 0){
                stk.top() *= N;
            } else if (index == 1){
                stk.top() /= N;
            } else if (index == 2){
                stk.push(N);
            } else {
                stk.push(-N);
            }
            index = (index + 1) % 4;
            N--;
        }
        int sum = 00;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};

int main()
{
    
    return 0;
}
