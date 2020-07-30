#include <bits/stdc++.h>
#include "my_unordered_mp.h"
using namespace std;

class test{
public:
    vector<int> findMax(vector<int> nums){
        stack<int> s;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            while (!s.empty() && nums[i] > nums[s.top()]){
                res.push_back(i);
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

struct TreeNode{
    int val;
    TreeNode* left, * right;
};

int main(){
    TreeNode* root = new TreeNode();
    root->val = 0;
    TreeNode* left = new TreeNode();
    left->val = 1;
    TreeNode* right = new TreeNode();
    right->val = 2;
    root->left = left;
    root->right = right;
    swap(root->left, root->right);
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    delete root;
    delete left;
    delete right;
    return 0;
};