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
    vector<vector<int>> res;
    void dfs(TreeNode* root, vector<int> &cur, int cursum){
        if (root == nullptr){
            return;
        }
        cursum -= root->val;
        cur.push_back(root->val);
        if (cursum == 0 && root->left == nullptr && root->right == nullptr){
            res.push_back(cur);
        }
        dfs(root->left, cur, cursum);
        dfs(root->right, cur, cursum);
        cur.pop_back();
    };
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return res;
        }
        vector<int> cur;
        dfs(root, cur, sum);
        return res;
    }
};

int main()
{
   
   return 0;
}
