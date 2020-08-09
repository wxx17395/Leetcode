#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    Node* dfs(Node* head, unordered_map<Node*, Node*> &visited){
        if (!head) return head;
        if (visited.find(head) != visited.end()){
            return visited[head];
        }
        Node* node = new Node(head->val);
        visited[head] = node;
        node->next = dfs(head->next, visited);
        node->random = dfs(head->random, visited);
        return node;
    }
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> visited;
        return dfs(head, visited);
    }
};

int main()
{
    
    return 0;
}
