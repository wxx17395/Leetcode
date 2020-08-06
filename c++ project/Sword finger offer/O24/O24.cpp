#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v){};
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* hair = new ListNode(-1);
        while (head) {
            ListNode* node = head->next;
            head->next = hair->next;
            hair->next = head;
            head = node;
        }
        return hair->next;
    }
};

int main()
{
   
   return 0;
}
