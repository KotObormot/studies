#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//#include <SimpleTimer.h>

#define MUTEX_ORDER false

std::mutex mtx1;
std::mutex mtx2;

void Print() {
#if MUTEX_ORDER
    mtx1.lock();
#else
    mtx2.lock();
#endif
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
#if MUTEX_ORDER
    mtx2.lock();
#else    
    mtx1.lock();
#endif
    
    for(int i(0); i < 5; ++i) {
        for(int j(0); j < 10; ++j) {
            std::cout << '*';
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << "\n";
    }
    std::cout << "\n";
#if MUTEX_ORDER
    mtx1.unlock();
#else
    mtx2.unlock();
#endif
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
#if MUTEX_ORDER
    mtx2.unlock();
#else    
    mtx1.unlock();
#endif
}

void Print2() {
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mtx2.lock();
    
    for(int i(0); i < 5; ++i) {
        for(int j(0); j < 10; ++j) {
            std::cout << '#';
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    mtx2.unlock();
    mtx1.unlock();
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    std::thread t1(Print);
    std::thread t2(Print2);

    t1.join();
    t2.join();

    std::cout << "FINISH MAIN\n";

}