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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *node = root, *pre = nullptr;
        TreeNode *x = nullptr, *y = nullptr;
        while (node != nullptr || !s.empty()){
            while (node != nullptr){
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            if (pre != nullptr && node->val < pre->val){
                y = node;
                if (x == nullptr){
                    x = pre;
                } else {
                    break;
                }
            }
            pre = node;
            node = node->right;
        }
        swap(x->val, y->val);
    }
};

int main()
{
   
   return 0;
}
