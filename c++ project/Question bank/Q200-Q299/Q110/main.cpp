#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
};

class Solution{
public:
    bool isBalanced(TreeNode* root){
        return recur(root) != -1;
    }

    int recur(TreeNode* root){
        if (!root){
            return 0;
        }
        int left = recur(root->left);
        if (left == -1) {
            return -1;
        }
        int right = recur(root->right);
        if (right == -1){
            return -1;
        }
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
