#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool check(ListNode* head, TreeNode* root){
        if (!head){
            return true;
        }
        if (!root){
            return false;
        }
        if (root->val != head->val){
            return false;
        }
        return check(head->next, root->left) || check(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head){
            return true;
        }
        if (!root){
            return false;
        }
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};



int main() {

    return 0;
}
