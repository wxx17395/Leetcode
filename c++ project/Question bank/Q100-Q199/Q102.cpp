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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int length = q.size();
            vector<int> cur;
            for (int i = 0; i < length; ++i){
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->ri ght){
                    q.push(node->right);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
