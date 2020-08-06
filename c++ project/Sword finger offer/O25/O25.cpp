#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v){};
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        /*int l1v, l2v;
        while (l1 || l2){
            l1v = l1 ? l1->val : INT_MAX;
            l2v = l2 ? l2->val : INT_MAX;
            if (l1v > l2v){
                node->next = l2;
                l2 = l2->next;
            } else {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }*/
        while (l1 && l2){
            if (l1->val > l2->val){
                node->next = l2;
                l2 = l2->next;
            } else {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }
        if (l1) {
            node->next = l1;
        }
        if (l2) {
            node->next = l2;
        }
        return head->next;   
    }
};

int main()
{
   
   return 0;
}
