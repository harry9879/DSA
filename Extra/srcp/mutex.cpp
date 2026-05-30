#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore
{
private:
    int count;             // Available resources
    mutex mtx;             // Mutex for synchronization
    condition_variable cv; // To block/wake threads

public:
    Semaphore(int count) : count(count) {}

    // wait() -> acquire resource
    void wait()
    {
        unique_lock<mutex> lock(mtx);

        // Wait until count > 0
        cv.wait(lock, [&]()
                { return count > 0; });

        count--; // consume resource
    }

    // signal() -> release resource
    void signal()
    {
        unique_lock<mutex> lock(mtx);
        count++;         // release resource
        cv.notify_one(); // wake one waiting thread
    }
};
Semaphore sem(2); // Only 2 threads allowed at once

void task(int id)
{
    sem.wait(); // acquire

    cout << "Thread " << id << " entered critical section\n";
    this_thread::sleep_for(chrono::seconds(2));

    cout << "Thread " << id << " leaving\n";

    sem.signal(); // release
}

int main()
{
    thread t1(task, 1);
    thread t2(task, 2);
    thread t3(task, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}