#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node){
                out << node->val << ' ';
                q.push(node->left);
                q.push(node->right);
            } else {
                out << "null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val){
            if (val == "null"){
                vec.push_back(nullptr);
            } else {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1, n = vec.size();
        for (int i = 0; j <vec.size(); ++i){
            if (vec[i] == nullptr) continue;
            if (j < n) vec[i]->left = vec[j++];
            if (j < n) vec[i]->right = vec[j++];
        }
        return vec[0];
    }
};

int main()
{
   
   return 0;
}
