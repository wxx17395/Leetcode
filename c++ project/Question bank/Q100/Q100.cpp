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
    bool dfs(TreeNode* A, TreeNode* B){
        if (!A && !B){
            return true;
        }
        if ((A && !B) || (!A && B) || (A->val != B->val)){
            return false;
        }
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};

int main()
{
   
   return 0;
}
