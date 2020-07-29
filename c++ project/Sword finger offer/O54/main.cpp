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
    int kthLargest(TreeNode* root, int k) {
        vector<int> dp;
        dfs(root, dp);
        return dp[k - 1];
    }

private:
    static void dfs(TreeNode *root, vector<int> &dp){
        if (!root){
            return;
        }
        dfs(root->right, dp);
        dp.emplace_back(root->val);
        dfs(root->left, dp);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    priority_queue<int> a;
    for(int i = 0; i < 10; ++i){
        int b;
        cin >> b;
        a.push(b);
    }
    for(int i = 0; i < 10; ++i){
        cout << a.top() << endl;
        a.pop();
    }
    return 0;
}
