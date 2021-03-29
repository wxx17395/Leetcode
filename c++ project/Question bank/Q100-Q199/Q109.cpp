#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0){};
    ListNode(int v): val(v){};
    ListNode(int v, ListNode* n): val(v), next(n){};
};

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
private:
    TreeNode* dfs(vector<int> &nums, int l, int r){
        if (l > r){
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head){
            nums.push_back(head->val);
            head = head->next;
        }    
        return dfs(nums, 0, nums.size() - 1);
    }
};

int main()
{
   
   return 0;
}
