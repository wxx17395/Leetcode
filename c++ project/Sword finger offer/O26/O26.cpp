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
    bool check(TreeNode* A, TreeNode* B){
        if (B == nullptr){
            return true;
        } 
        if (A == nullptr || A->val != B->val ){
            return false;
        }
        return check(A->left, B->left) && check(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return false;
        queue<TreeNode*> q;
        q.push(A);
        while (!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node->val == B->val && check(node, B)){
                return true;
            }
            if (node->left){
                q.push(node->left);
            }
            if (node->right){
                q.push(node->right);
            }
        }
        return false;
    }
};

int main()
{
   
   return 0;
}
