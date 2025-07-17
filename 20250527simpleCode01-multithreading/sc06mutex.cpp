#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//#include <SimpleTimer.h>

std::mutex mtx;

void Print(char ch) {
    mtx.lock();
    for(int i(0); i < 5; ++i) {
        for(int j(0); j < 10; ++j) {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    mtx.unlock();
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    std::thread t1(Print, '*');
    std::thread t2(Print, '#');
    std::thread t3(Print, '@');

    t1.join();
    t2.join();
    t3.join();

    std::cout << "FINISH MAIN\n";

}