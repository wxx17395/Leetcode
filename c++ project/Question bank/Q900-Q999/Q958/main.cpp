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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool flag = false;
        while (!dq.empty()){
            int length = dq.size();
            for (int i = 0; i< length; ++i){
                TreeNode* node = dq.front(); dq.pop_front();
                if (node != nullptr){
                    if (flag) return false;
                    dq.push_back(node->left);
                    dq.push_back(node->right);
                } else{
                    flag = true;
                }
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
