#include <bits/stdc++.h>
using namespace std;

class Foo {
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lk(g_mutex);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++counter;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(g_mutex);
        cv1.wait(lk, [this](){return counter == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++counter;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(g_mutex);
        cv2.wait(lk, [this](){return counter == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    int counter = 1;
    condition_variable cv1;
    condition_variable cv2;
    mutex g_mutex;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
