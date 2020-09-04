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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sorted(vector<int> &nums, int l, int r){
        if (l > r){
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sorted(nums, l, mid - 1);
        node->right = sorted(nums, mid + 1, r);
        return node;
    }
};

void show(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << endl;
        if (node->left){
            q.push(node->left);
        }
        if (node->right){
            q.push(node->right);
        }
    }
}

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* node = Solution().sortedArrayToBST(nums);
    show(node);
    return 0;
}
