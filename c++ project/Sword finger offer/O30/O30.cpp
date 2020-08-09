#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> mains;
    stack<int> sups;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        mains.push(x);
        if (sups.empty() || x <= sups.top()){
            sups.push(x);
        }
    }
    
    void pop() {
        if (!sups.empty() && sups.top() == mains.top()){
            sups.pop();
        }
        mains.pop();
    }
    
    int top() {
        return mains.top();
    }
    
    int min() {
        return sups.top();
    }
};

int main()
{
    
    return 0;
}
