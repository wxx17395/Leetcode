#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        ListNode* newHead = new ListNode(-1);
        unordered_map<int, bool> visited;
        newHead->next = head;
        ListNode* pre = newHead;
        while (head){
            if (visited[head->val] == true){
                pre->next = head->next;
            }else{
                pre = pre->next;
                visited[head->val] = true;
            }
            head = head->next;
        }
        return newHead->next;
    }
};

int main() {

    return 0;
}
