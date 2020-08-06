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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode *A, *B;
        while (q.size() > 0){
            A = q.front(); q.pop();
            B = q.front(); q.pop();
            if (A->val != B->val){
                return false;
            } 
            if ((A->left && !B->right) || (!A->left && B->right) || (A->right && !B->left) || (!A->right && B->left)){
                return false;
            }
            if (A->left && B->right){
                q.push(A->left);
                q.push(B->right);
            }
            if (A->right && B->left){
                q.push(A->right);
                q.push(B->left);
            }
        }
        return true;
    }
};

int main()
{
   
   return 0;
}
