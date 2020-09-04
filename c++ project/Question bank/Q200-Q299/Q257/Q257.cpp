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
public:
    vector<int> cur;
    vector<string> res;
    void vectostr(){
        int n = cur.size();
        string s;
        for (int i = 0; i < n; ++i){
            s += to_string(cur[i]);
            if (i < n - 1){
                s += "->";
            }
        }
        res.push_back(s);
    }
    void dfs(TreeNode* root){
        if (root == nullptr){
            return;
        }
        cur.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr){
            vectostr();
        } else {
            dfs(root->left);
            dfs(root->right);
        }
        cur.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main()
{
   
   return 0;
}
