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
private:
    void dfs(TreeNode *root, vector<int> &dp){
        if (!root){
            return;
        }
        dfs(root->right, dp);
        dp.push_back(root->val);
        dfs(root->left, dp);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        dfs(root, res);
        return res[k - 1];
    }
};

int main()
{
   
   return 0;
}
