#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        stack<Node*> s;
        Node* node = root;
        Node* head = new Node(-1);
        Node* pre = head;
        Node* last = nullptr;
        while (node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            pre->right = node;
            node->left = pre;
            pre = pre->right;
            if (!node->right) last = node;
            node = node->right;
        }
        last->right = head->right;
        head->right->left = last;
        return head->right;
    }
};

int main()
{
    
    return 0;
}
