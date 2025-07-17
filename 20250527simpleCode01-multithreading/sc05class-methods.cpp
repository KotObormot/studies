#include <iostream>
#include <thread>
#include <chrono>

#define DE_TACH false

class MyClass {
  public:
    void DoWork() {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << std::this_thread::get_id() << "\t=========\tDoWork STARTED\t=================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));        
        std::cout << std::this_thread::get_id() << "\t=========\tDoWork STOPPED\t=================\n";
    }

    void DoWork2(int a) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << std::this_thread::get_id() << "\t=========\tDoWork2 STARTED\t=================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "DoWork2 a = " << a << "\n";        
        std::cout << std::this_thread::get_id() << "\t=========\tDoWork2 STOPPED\t=================\n";
    }

    int Sum(int a, int b) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << std::this_thread::get_id() << "\t=========\tSum STARTED\t=================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << std::this_thread::get_id() << "\t=========\tSum STOPPED\t=================\n";
        return a + b;
    }
};

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    MyClass m;
    int result;
    
    std::thread t([&result, &m]() {                 // [&]  - захват лямбдой всех выше объявленных внешних переменных
        result = m.Sum(2, 5);
    });

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
    
    std::cout << "Result Sum = " << result << "\n";
    std::cout << "FINISH MAIN\n";

}