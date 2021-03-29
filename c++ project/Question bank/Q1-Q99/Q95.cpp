#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return partition(1, n);
    }

private:
    vector<TreeNode*> partition(int l, int r){
        vector<TreeNode*> ret;
        if (l > r){
            return {nullptr};
        }
        for (int i = l; i <= r; ++i){
            vector<TreeNode*> left = partition(l, i - 1);
            vector<TreeNode*> right = partition(i + 1, r);
            for (auto& l : left){
                for (auto& r : right){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
