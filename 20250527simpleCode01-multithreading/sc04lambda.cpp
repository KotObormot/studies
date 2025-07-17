#include <iostream>
#include <thread>
#include <chrono>

#define DE_TACH false
#define AUTO_F false

int Sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << std::this_thread::get_id() << "\t=========\tSum STARTED\t=================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    
    std::cout << std::this_thread::get_id() << "\t=========\tSum STOPPED\t=================\n";
    return a + b;
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    int result;
#if AUTO_F
    auto f = [&result]() { result = Sum(2, 5);};    // на самом деле, этот объект лишний
    std::thread t(f);
#else
    std::thread t([&result]() {
        result = Sum(2, 5); 
    });
#endif
        
    for(size_t i(0); i < 10; ++i) {
        std::cout << i << ")" 
                  << " " << std::this_thread::get_id()
                  << " main"
                  << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
#if DE_TACH
    t.detach();
#else
    t.join();
#endif
    
    std::cout << "Result = " << result << "\n";

    std::cout << "FINISH MAIN\n";

}