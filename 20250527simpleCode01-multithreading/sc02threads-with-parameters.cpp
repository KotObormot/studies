#include <iostream>
#include <thread>
#include <chrono>

#define DE_TACH false

void DoWork(int a, int b, std::string msg) {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "=========\t" << msg << "\t=================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "a + b = " << (a + b) << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "=========\tDoWork STOPPED\t=================\n";
}

int main() {
    std::cout << "Hello!\n";
    std::cout << std::thread::hardware_concurrency() << "\n";
    std::thread th(DoWork, 2, 3, "DoWork STARTED");
    std::cout << "START MAIN\n";
    for(size_t i(0); true; ++i) {
        std::cout << i << ")" 
                  << " " << std::this_thread::get_id()
                  << " main"
                  << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "FINISH MAIN\n";

    th.join();
}