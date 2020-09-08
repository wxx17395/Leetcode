#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int key, value;
    ListNode *next, *pre;
    ListNode(){};
    ListNode(int k, int v): key(k), value(v){};
};

class LRU{
public:
    LRU(int n){
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->pre = head;
        capacity = n;
    }

    int get(int key){
        if (cache.find(key) == cache.end()){
            return -1;
        }
        int value = cache[key]->value;
        move_to_head(cache[key]);
        return value;
    }

    void put(int key, int value){
        if (size == capacity){
            del();
        }
        ListNode* node = new ListNode(key, value);
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
    }

    void move_to_head(ListNode* node){
        if (node->pre = head){
            return;
        }
        node->pre->next = node->next;
        node->next->pre = node->pre;
        head->next->pre = node;
        node->pre = head;
        node->next = head->next;
        head->next = node;
    }

    void del(){
        ListNode* node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;
        cache.erase(node->key);
        --size;
        delete node;
    }

    ~LRU(){
        while (head->next != tail){
            delete head->next;
        }
        delete head;
        delete tail;
    }

private:
    unordered_map<int, ListNode*> cache;
    ListNode* head;
    ListNode* tail;
    int size = 0;
    int capacity;
};

int main()
{
   
   return 0;
}
