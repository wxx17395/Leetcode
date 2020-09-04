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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()){
            while (node){
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2);
    TreeNode* root3 = new TreeNode(3);
    root->right = root2;
    root2->left = root3;
    Solution().inorderTraversal(root);
    delete root, root2, root3;
    return 0;
}
