#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
    vector<int> v;
    int front, back;
    int size;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k + 1;
        v.assign(size, 0);
        front = 0;
        back = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front + size - 1) % size;
        v[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        v[back] = value;
        back = (back + 1) % size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        back = (back + size - 1) % size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return v[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return v[(back + size - 1) % size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == back;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (back + 1) % size == front;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
