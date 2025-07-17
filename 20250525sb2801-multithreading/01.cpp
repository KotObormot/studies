#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <thread>   // нить

void wait_for_call() {
    std::this_thread::sleep_for(std::chrono::seconds(10));  // интервал ожидания 10 сек
    std::cout << "RING (Courier)" << "\n";
}

int main() {
    std::cout << "Hello!\n";
    std::thread call(wait_for_call);
    std::this_thread::sleep_for(std::chrono::seconds(5));   // интервал ожидания 5 сек
    std::cout << "RING (Friend)" << "\n";
    call.join();
    std::cout << "5 seconds passed. Answering a friend's call.." << "\n";
    std::cout << "10 seconds passed. Answering courier's call." << "\n";
}