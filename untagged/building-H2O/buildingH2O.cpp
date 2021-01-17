class H2O {
public:
    H2O():n_hyd(0) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mutex_h);
        cv.wait(lock, [this]{return n_hyd<2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        n_hyd+=1;
        lock.unlock();
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mutex_h);
        cv.wait(lock, [this]{return n_hyd>=2;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        n_hyd-=2;
        lock.unlock();
        cv.notify_all();
        
    }
private:
    mutex mutex_h;
    condition_variable cv;
    int n_hyd;
};