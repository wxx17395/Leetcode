#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v){};
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return 0;
        ListNode* hair = head;
        int count = 1;
        while (head->next){
            ++count;
            head = head->next;
        }
        head->next = hair;
        for (int i = 0; i < count - (k % count) - 1; ++i){
            hair = hair->next;
        }
        ListNode* node = hair->next;
        hair->next = nullptr;
        return node;
    }
};

int main()
{
   
   return 0;
}
