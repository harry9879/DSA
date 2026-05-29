#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

using namespace std;

// Semaphore class
class Semaphore
{
private:
    int count;
    mutex mtx;
    condition_variable cv;

public:
    Semaphore(int count) : count(count) {}

    void wait()
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]()
                { return count > 0; });
        count--;
    }

    void signal()
    {
        unique_lock<mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

// Buffer
queue<int> buffer;
const int BUFFER_SIZE = 5;

// Semaphores
Semaphore empty(BUFFER_SIZE);
Semaphore full(0);
Semaphore mutexSem(1); // acts like mutex

// Producer
void producer()
{
    for (int i = 1; i <= 10; i++)
    {
        empty.wait();    // wait if buffer full
        mutexSem.wait(); // enter critical section

        buffer.push(i);
        cout << "Produced: " << i << endl;

        mutexSem.signal(); // exit critical section
        full.signal();     // increase filled slots

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Consumer
void consumer()
{
    for (int i = 1; i <= 10; i++)
    {
        full.wait();     // wait if buffer empty
        mutexSem.wait(); // enter critical section

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << endl;

        mutexSem.signal(); // exit critical section
        empty.signal();    // increase empty slots

        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}