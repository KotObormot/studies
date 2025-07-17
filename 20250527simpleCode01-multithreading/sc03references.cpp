#include <iostream>
#include <thread>
#include <chrono>

#define DE_TACH false

void DoWork(int& a) {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << std::this_thread::get_id() << "\t=========\tDoWork STARTED\t=================\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    a *= 2;
    std::cout << std::this_thread::get_id() << "\t=========\tDoWork STOPPED\t=================\n";
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";
    int q;
    std::cout << "q--> ";
    std::cin >> q;

    std::thread th(DoWork, std::ref(q));    // передача параметра в функцию в потоке по ссылке
    
    for(size_t i(0); i < 10; ++i) {
        std::cout << i << ")" 
                  << " " << std::this_thread::get_id()
                  << " main"
                  << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
#if DE_TACH
    th.detach();
#else
    th.join();
#endif
    std::cout << q << "\n";

    std::cout << "FINISH MAIN\n";

}