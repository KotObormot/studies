#include <exception>
#include <iostream>
#include <print>
#include <format>
#include <vector>

int h() {
    std::println("Старт h");
//    throw std::exception();
    std::println("После исключения");
    return 10;
}

int g() {
    std::println("Старт g");
    int res = h();
    std::println("После h");
    return res * 3;
}

int f() {
    try {
        return g() + 12;
    }
    catch(std::exception e) {
        std::println("Поймано", f());
        std::cout << e.what() << "\n";
    }
    return 0;
}

int main() {    
    std::println("Hello World! {}", f());
}
