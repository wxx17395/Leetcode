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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int i, int j, int k){
        if (j > k) return nullptr;
        TreeNode* node = new TreeNode(preorder[i]);
        int cur;
        for(int m = j; m <= k; ++m){

            if (inorder[m] == node->val){
                cur = m;
                break;
            }
        }
        node->left = build(preorder, inorder, i + 1, j, cur - 1);
        node->right = build(preorder, inorder, i + (cur - j) + 1, cur + 1, k);
        return node;
    }
};


int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution().buildTree(preorder, inorder);
    return 0;
}
