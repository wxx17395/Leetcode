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
    int res = 0;
    void dfs(TreeNode* root, int up, int down){
        if (!root) return;
        res = max(res, max(abs(root->val - up), abs(root->val - down)));
        up = max(up, root->val);
        down = min(down, root->val);
        dfs(root->left, up, down);
        dfs(root->right, up, down);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val, root->val);
        return res;
    }
};

int main()
{
   
   return 0;
}
