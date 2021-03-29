#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
private:
    int sum = 0;
    void recursion(TreeNode* root){
        if (root == nullptr){
            return;
        }
        recursion(root->right);
        sum += root->val;
        root->val = sum;
        recursion(root->left);
        return;
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        recursion(root);
        return root;
    }
};

int main()
{
   
   return 0;
}
