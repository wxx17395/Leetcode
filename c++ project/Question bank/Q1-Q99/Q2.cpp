#include <bits/stdc++.h>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v){};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* head = new ListNode(-1);
        ListNode* res = head;
        while (l1 && l2){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = flag + x + y;
            int a = sum % 10;
            flag = sum / 10;
            ListNode* node = new ListNode(a);
            head->next = node;
            head = head->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (flag == 1){
            ListNode* node = new ListNode(1);
            head->next = node;
        }
        return res->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
