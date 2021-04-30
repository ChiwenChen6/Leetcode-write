class Foo {
    
    boolean firstDone, secondDone; 
    Lock lock;
    
    public Foo() {
        firstDone = secondDone = false; 
        lock = new ReentrantLock(); 
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        synchronized(lock) {
            printFirst.run();
            firstDone = true; 
            lock.notifyAll(); 
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        // printSecond.run() outputs "second". Do not change or remove this line.
        synchronized(lock) {
            while(!firstDone) {
                lock.wait(); 
            } 
            printSecond.run();
            secondDone = true; 
            lock.notifyAll(); 
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        // printThird.run() outputs "third". Do not change or remove this line.
        synchronized(lock) {
            while(!firstDone || !secondDone) {
                lock.wait(); 
            } 
            printThird.run();
        }
    }
}
