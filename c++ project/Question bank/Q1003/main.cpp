#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        for (auto ch : S){
            if (ch == 'a' || ch == 'b'){
                s.push(ch);
            }else{
                if (s.size() < 2 || s.top() != 'b' ){
                    return false;
                }
                s.pop();
                if (s.size() < 1 || s.top() != 'a' ){
                    return false;
                }
                s.pop();
            }
        }
        return s.size() == 0;
    }
};

int main() {
    string S = "abccba";
    cout << Solution().isValid(S) << endl;
    return 0;
}
