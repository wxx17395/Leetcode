#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 分治法
/*class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        if (!a || !b) return a ? a : b;
        ListNode head = ListNode(-1), *tail = &head, *aptr = a , *bptr = b;
        while (aptr && bptr){
            if (aptr->val < bptr->val){
                tail->next=aptr;
                aptr = aptr->next;
            }else{
                tail->next=bptr;
                bptr = bptr->next;
            }
            tail = tail->next;
        }
        tail->next = (aptr ? aptr : bptr);
        return head.next;
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r){
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return merge2Lists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
};*/

// 优先队列
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (auto node : lists){
            if (node){
                q.push({node->val, node});
            }
        }
        ListNode head = ListNode(-1), *tail = &head;
        while (!q.empty()){
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            if (f.ptr->next){
                q.push({f.ptr->next->val, f.ptr->next});
            }
            tail = tail->next;
        }
        return head.next;
    }

private:
    struct status{
        int val;
        ListNode *ptr;
        bool operator < (const status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue<status> q;

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
