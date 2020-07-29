#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.emplace(value);
        ++size;
    }

    int deleteHead() {
        if (size == 0){
            return -1;
        }
        if (s2.empty()){
            while(!s1.empty()){
                s2.emplace(s1.top());
                s1.pop();
            }
        }
        --size;
        int res = s2.top();
        s2.pop();
        return res;
    }

private:
    stack<int> s1;
    stack<int> s2;
    int size = 0;
};

int main() {
    return 0;
}
