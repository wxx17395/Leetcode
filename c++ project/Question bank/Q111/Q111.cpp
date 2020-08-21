#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr){
            return 1;
        }
        int cur = INT_MAX;
        if (root->left != nullptr){
            cur = min(cur, minDepth(root->left));
        }
        if (root->right != nullptr){
            cur = min(cur, minDepth(root->right));
        }
        return cur + 1;
    }
};

int main()
{
   
   return 0;
}
