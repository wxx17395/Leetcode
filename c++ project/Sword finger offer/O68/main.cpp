#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 86 - 1
/*class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int little = p->val, big = q->val;
        if (little > big) swap(little, big);
        while (root){
            if (root->val > big){
                root = root->left;
            } else if (root->val < little){
                root = root->right;
            } else{
                break;
            }
        }
        return root;
    }

};*/

// 86 - 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* inleft = lowestCommonAncestor(root->left, p, q);
        TreeNode* inright = lowestCommonAncestor(root->right, p, q);

        if (inleft == nullptr) return inright;
        if (inright == nullptr) return inleft;
        return root;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
