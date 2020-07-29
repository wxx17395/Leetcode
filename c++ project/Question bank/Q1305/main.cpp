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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        r1 = inorder(root1);
        r2 = inorder(root2);
        int m = r1.size(), n = r2.size();
        vector<int> res(m + n, 0);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n){
            if (r1[i] < r2[j]){
                res[k++] = r1[i++];
            }else{
                res[k++] = r2[j++];
            }
        }
        while (i < m){
            res[k++] = r1[i++];
        }
        while (j < n){
            res[k++] = r2[j++];
        }
        return res;
    }

private:
    vector<int> inorder(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || s.size()){
            while (node){
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
