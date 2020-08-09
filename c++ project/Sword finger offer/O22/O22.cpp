#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v){};
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; ++i){
            node = node->next;
        }
        while (node){
            node = node->next;
            head = head->next;
        }
        return head;
    }
};


int main()
{
   
   return 0;
}
