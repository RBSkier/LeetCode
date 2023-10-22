#include <semaphore>

class FooBar {
 private:
    int n;
    std::counting_semaphore<1> sem1;
    std::counting_semaphore<1> sem2;
 public:
    FooBar(int n) : sem1(1), sem2(0){
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem1.acquire();
            printFoo();
            sem2.release();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem2.acquire();
            printBar();
            sem1.release();
        }
    }
};