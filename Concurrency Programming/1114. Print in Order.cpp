#include <mutex>
#include <condition_variable>

class Foo {
private:
    std::mutex mtx;
    std::condition_variable firstDone, secondDone;
    int state = 0;
public:
    void first(function<void()> printFirst) {
        std::lock_guard<std::mutex> guard(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 1;
        firstDone.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(mtx);
        firstDone.wait(lk, [this](){ return state == 1; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 2;
        secondDone.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(mtx);
        secondDone.wait(lk, [this](){ return state == 2; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
