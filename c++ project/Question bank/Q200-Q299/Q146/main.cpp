#include <bits/stdc++.h>
using namespace std;

struct DListNode{
    int key;
    int value;
    DListNode* next;
    DListNode* pre;
    DListNode(int k, int v) : key(k), value(v){};
};

class LRUCache {
    unordered_map<int, DListNode*> cache;
    DListNode* head;
    DListNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new DListNode(0,0);
        tail = new DListNode(0,0);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key)){
            return -1;
        }
        DListNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)){
            DListNode* node = new DListNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity){
                DListNode* rnode = removeTail();
                cache.erase(rnode->key);
                delete rnode;
                --size;
            }
        } else {
            DListNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    void addToHead(DListNode* node){
        node->pre = head;
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
    }

    void moveToHead(DListNode* node){
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DListNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    DListNode* removeTail(){
        DListNode* rnode = tail->pre;
        removeNode(rnode);
        return rnode;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
