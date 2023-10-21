class Foo {
    private volatile int state = 0;
    private ReentrantLock fooLock = new ReentrantLock();
    private Condition firstDone = fooLock.newCondition();
    private Condition secondDone = fooLock.newCondition();

    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        fooLock.lock();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        state = 1; //mark state as first done.
        firstDone.signalAll();
        fooLock.unlock();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        fooLock.lock();
        while(state != 1)
            firstDone.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        state = 2;
        secondDone.signalAll();
        fooLock.unlock();
    }

    public void third(Runnable printThird) throws InterruptedException {
        fooLock.lock();
        while(state != 2)
            secondDone.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        fooLock.unlock();
    }
}
