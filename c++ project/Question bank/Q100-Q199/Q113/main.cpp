#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int>> res;
    void dfs(TreeNode* &root, vector<int>& t, int sum){
        if (!root){
            return;
        }
        t.push_back(root->val);
        if (root->val == sum && !root->left && !root->right){
            res.push_back(t);
        }
        if (root->left){
            dfs(root->left, t, sum - root->val);
        }
        if (root->right){
            dfs(root->right, t, sum - root->val);
        }
        t.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> t;
        dfs(root, t, sum);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(4);
    TreeNode* right = new TreeNode(8);
    root->left = left;
    root->right = right;
    Solution().pathSum(root,13);
    delete root;
    delete left;
    delete right;
    return 0;
}
