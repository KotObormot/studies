#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//#include <SimpleTimer.h>

std::mutex mtx;

void Print(char ch) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    {   // начало области видимости lock_gard'a
        std::lock_guard<std::mutex> guard(mtx);
        for(int i(0); i < 5; ++i) {
            for(int j(0); j < 10; ++j) {
                std::cout << ch;
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }   // конец области видимости lock_gard'a
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    std::thread t1(Print, '*');
    std::thread t2(Print, '#');

    t1.join();
    t2.join();

    std::cout << "FINISH MAIN\n";

}