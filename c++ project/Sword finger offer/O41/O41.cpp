#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> g;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (l.size() == g.size()){
            g.push(num);
            l.push(g.top());
            g.pop();
        } else {
            l.push(num);
            g.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        double res;
        if (l.size() == g.size()){
            res = (l.top() + g.top()) / 2.0; 
        } else {
            res = l.top();
        }
        return res;
    }
};

int main()
{
    
    return 0;
}
