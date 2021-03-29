#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* head = new ListNode(-1);
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int flag = 0;
        while (s1.size() || s2.size()){
            int a = s1.size() ? s1.top() : 0;
            int b = s2.size() ? s2.top() : 0;
            int sum = a + b + flag;
            int d = sum % 10;
            flag = sum / 10;
            ListNode* node = new ListNode(d);
            node->next = head->next;
            head->next = node;
            if (s1.size()) s1.pop();
            if (s2.size()) s2.pop();
        }
        if (flag){
            ListNode* node = new ListNode(1);
            node->next = head->next;
            head->next = node;
        }
        return head->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
