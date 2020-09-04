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
    // 递归
    /*bool hasPathSum(TreeNode* root, int sum) {
        if (!root){
            return false;
        }
        sum -= root->val;
        return (sum == 0 && !root->left && !root->right) || hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }*/

    // 层次遍历
    /*bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        queue<TreeNode*> q;
        queue<int> path;
        q.push(root);
        path.push(root->val);
        while (!q.empty()){
            int length = q.size();
            for (int i = 0; i < length; ++i){
                TreeNode* node = q.front(); q.pop();
                int cur = path.front(); path.pop();
                if (!node->left && !node->right && cur == sum) return true;
                if (node->left) {
                    q.push(node->left);
                    path.push(node->left->val + cur);
                }
                if (node->right){
                    q.push(node->right);
                    path.push(node->right->val + cur);
                }
            }
        }
        return false;
    }*/

    // dfs + 回溯
    bool dfs(TreeNode* &root, int sum){
        if (!root){
            return false;
        }
        if (root->val == sum && !root->left && !root->right){
            return true;
        }
        bool l, r;
        if (root->left){
            l = dfs(root->left, sum - root->val);
        }
        if (root->right){
            r = dfs(root->right, sum - root->val);
        }
        return l || r;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
