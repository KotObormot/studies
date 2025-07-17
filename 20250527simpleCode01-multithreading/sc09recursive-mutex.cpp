#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//#include <SimpleTimer.h>

std::recursive_mutex rm;

void Foo(int a) {
    rm.lock();
    std::cout << a << " ";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    if(a <= 1) {
        std::cout << "\n";
        rm.unlock();
        return;
    }
    a--;
    //--a;
    Foo(a);
    rm.unlock();
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    std::thread t1(Foo, 10);
    std::thread t2(Foo, 10);

    t1.join();
    t2.join();
    
    std::cout << "FINISH MAIN\n";

}