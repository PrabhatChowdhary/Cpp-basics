#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);  // Atomic variable to be shared between threads

void incrementCounter() {
    for (int i = 0; i < 100000; ++i) {
        counter.fetch_add(1);  // Atomically increment the counter
    }
}

int main() {
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "Counter value: " << counter.load() << std::endl;

    return 0;
}
