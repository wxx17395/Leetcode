//
// Created by DZKD on 2020/7/14.
//
#ifndef TEST_MY_UNORDERED_MP_H
#define TEST_MY_UNORDERED_MP_H
#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int key, value;
    ListNode* next;
    ListNode(int _key, int _value):key(_key),value(_value),next(nullptr){};
    ~ListNode() = default;
};

class HashFunc{
public:
    int operator () (const int key){
        return 3 * key + 1;
    }
};

class my_unordered_map{
private:
    vector<ListNode*> vec;
    int size, used;
    HashFunc hash;
    int intnull;

public:
    my_unordered_map(int x): size(x), intnull(-1){
        vec = vector<ListNode*>(x);
        for (int i = 0; i < x; ++i){
            ListNode* node = new ListNode(-1,-1);
            vec[i] = node;
        }
    }

    ~my_unordered_map(){
        /*for (auto ptr : vec){
            auto next = ptr;
            while (next){
                next = ptr->next;
                delete ptr;
            }
        }*/
    }

    void insert(int key, int value){
        int index = hash(key) % size;
        ListNode* node = new ListNode(key, value);
        vec[index]->next = node;
    }

    bool earse(int key){
        int index = hash(key) % size;
        ListNode* pre = vec[index];
        ListNode* node = pre->next;
        if (!node) return false;
        while (node){
            if (node->key == key){
                pre->next = node->next;
                delete node;
                return true;
            }
            pre = node;
            node = node->next;
        }
        return false;
    }

    int find(const int key){
        int index = hash(key) % size;
        ListNode* node = vec[index]->next;
        while (node){
            if (node->key == key){
                return node->value;
            }
            node = node->next;
        }
        return intnull;
    }

    int operator [](int key){
        return find(key);
    }

    void print (){
        cout << "my_unordered_map_print:\n";
        for (auto head: vec){
            while (head->next){
                head = head->next;
                cout << head->value << endl;
            }
        }
    }

};
#endif //TEST_MY_UNORDERED_MP_H
