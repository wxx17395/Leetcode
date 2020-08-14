#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x){};
};

class Solution {
private:
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail){
        ListNode* pre = tail;
        ListNode* p = head;
        while (pre != tail){
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return {tail, head};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head){
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i){
                tail = tail->next;
                if (!tail){
                    return hair->next;
                }
            }
            ListNode* next = tail->next;
            tie(head, tail) = reverse(head, tail);
            pre->next = head;
            head->next = next;
            pre = tail;
            head = head->next;
        }
        return hair->next;
    }
};

int main()
{
   
   return 0;
}
