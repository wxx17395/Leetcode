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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (not root) return res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()){
            while (node){
                s.push(node->left);
                res.push_back(node.val);
                node = node->right;
            }
            node = s.top();s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
