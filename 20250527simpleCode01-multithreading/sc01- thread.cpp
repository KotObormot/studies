#include <iostream>
#include <thread>
#include <chrono>

#define DE_TACH false

void DoWork() {
    std::cout << "START DoWork\n";
    for(size_t i(0); i < 10; ++i) {
        std::cout << i << ")" 
                  << " " << std::this_thread::get_id()
                  << " DoWork"
                  << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "\n";
    std::cout << "FINISH Dowork\n";
}

int main() {
    std::cout << "Hello!\n";

    //DoWork();
    std::thread th(DoWork); // отдельный поток от main
    std::thread th2(DoWork);
#if DE_TACH
    th.detach(); // разрыв связи между объектом и потоком
#else
    //th.join();
#endif
    std::cout << "START MAIN\n";
    for(size_t i(0); i < 10; ++i) {
        std::cout << i << ")" 
                  << " " << std::this_thread::get_id()
                  << " main"
                  << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\n";
    std::cout << "FINISH MAIN\n";

#if DE_TACH    
#else
    th.join();
    th2.join();
#endif

}