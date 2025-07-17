#include <iostream>
#include <thread>

void progressBar() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << "= ";
    }
}

int main() {
    std::cout << "Hello! Let's go!\n";
    std::thread th(progressBar);
    for(int i(0); i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << i << " ";
    }
    th.detach();
}