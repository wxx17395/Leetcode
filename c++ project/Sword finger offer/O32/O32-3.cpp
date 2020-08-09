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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;
        while (!q.empty()){
            int l = q.size();
            vector<int> cur;
            for (int i = 0; i < l; ++i){
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (flag == true){
                reverse(cur.begin(), cur.end());
            }
            flag = !flag;
            res.push_back(cur);
            
        }
        return res;
    }
};

int main()
{
   
   return 0;
}