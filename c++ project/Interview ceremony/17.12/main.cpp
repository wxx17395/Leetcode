#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        inorder(root, head);
        return head->right;
    }

    TreeNode* inorder(TreeNode* root, TreeNode* pre){
        if (root){
            pre = inorder(root->left, pre);
            root->left = nullptr;
            pre->right = root;
            pre = root;
            pre = inorder(root->right, pre);
        }
        return pre;
    }

    // 非递归，爆栈
    /*TreeNode* convertBiNode(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        TreeNode* head = new TreeNode(0);
        TreeNode* pre = head;
        while (node != nullptr || !s.empty()){
            while (node != nullptr){
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            pre->left = nullptr;
            pre->right = node;
            pre = node;
            node = node->right;
        }
        return head->right;
    }*/
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
