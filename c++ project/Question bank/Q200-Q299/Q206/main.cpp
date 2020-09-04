#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* hair = new ListNode(-1);
        while (head){
            ListNode* tmp = head->next;
            head->next = hair->next;
            hair->next = head;
            head = tmp;
        }
        return hair->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
