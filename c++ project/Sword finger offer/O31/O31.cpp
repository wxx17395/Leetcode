#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int> s;
        for (int i = 0; i < pushed.size(); ++i){
            s.push(pushed[i]);
            while (s.size() && popped[j] == s.top()){
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};

int main()
{
    
    return 0;
}
