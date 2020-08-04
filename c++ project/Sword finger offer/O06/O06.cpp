#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v){};
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> s;
        while (head){
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

int main()
{
   
   return 0;
}
