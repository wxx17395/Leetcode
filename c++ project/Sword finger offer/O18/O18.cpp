#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v){};
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* hair = new ListNode(-1);
        hair->next = head;
        ListNode* pre = hair;
        while (head && head->val != val){
            pre = head;
            head = head->next;
        }
        if (head){
            pre->next = head->next;
            head->next = nullptr;
        }
        return hair->next;
    }
};

int main()
{
   
   return 0;
}
