#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class BSTIterator {
private:
    vector<int> vec;
    void inorder(TreeNode* root){
        if (!root){
            return;
        }
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    int cur = 0;

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        ++cur;
        return vec[cur - 1];
    }
    
    bool hasNext() {
        if (cur <= vec.size() - 1){
            return true;
        }
        return false;
    }
};

int main()
{
   
   return 0;
}
