#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x){};
};

class Solution {
public:
    /*ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while(node1 != node2){
            node1 = node1 ? node1->next : headB;
            node2 = node2 ? node2->next : headA;
        }
        return node1;
    }*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        int l1 = 0, l2 = 0;
        while (node1){
            ++l1;
            node1 = node1->next;
        }
        while (node2){
            ++l2;
            node2 = node2->next;
        }
        if (l1 < l2){
            swap(headA, headB);
            swap(l1, l2);
        }
        node1 = headA;
        node2 = headB;
        for (int i = 0; i < l1 - l2; ++i){
            node1 = node1->next;
        }
        while (node1 != node2){
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};

int main()
{
   
   return 0;
}
