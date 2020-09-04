#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* del(TreeNode* root){
        if (root->left && !root->right) return root->left;
        if (root->right && !root->left) return root->right;
        if (!root->left && !root->right) return nullptr;
        TreeNode* node = root->left->right;
        TreeNode* r = root->right;
        root->left->right = root->right;
        if (node){
            while (r->left){
                r = r->left;
            }
            r->left = node;
        }
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* head = new TreeNode(-1);
        head->left = root;
        bool left = true;
        TreeNode* pre = head;
        while (root){
            if (root->val > key){
                left = true;
                pre = root;
                root = root->left;
            } else if (root->val < key){
                left = false;
                pre = root;
                root = root->right;
            } else {
                if (left) pre->left = del(root);
                else pre-> right = del(root);
                break;
            }
        }
        return head->left;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
