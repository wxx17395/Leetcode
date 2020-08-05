#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

/*class Solution {
private:
    // false = no, true = yes
    int dfs(TreeNode* root, bool steal){
        if (root == nullptr) {
            return 0;
        }
        int val = root->val;
        int lmax = dfs(root->left, !steal), rmax = dfs(root->right, !steal);
        if (steal == false){
            val = 0;
            lmax = max(lmax, dfs(root->left, steal));
            rmax = max(rmax, dfs(root->right, steal));
        }
        return lmax + rmax + val;
    }
public:
    int rob(TreeNode* root) {
        return max(dfs(root, false), dfs(root, true));
    }
};*/

class Solution {
private:
    unordered_map<TreeNode*, int> f, g;
    void dfs(TreeNode* root){
        if (root == nullptr){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        f[root] = g[root->left] + g[root->right] + root->val;
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);

    }
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};

class Solution {
public:
    int rob(TreeNode* root) {

    }
};

int main()
{
   
   return 0;
}
