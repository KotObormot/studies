// https://www.youtube.com/watch?v=PTRyRuffT1Y
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>
#include <print>

int main() {
    
    std::vector<int> v = {1, 2, 3};
   
   try{ 
        std::println("v[3] = {}", v.at(3));
   }
   catch(std::exception ex) {
       std::cout << ex.what() << "\n";
   }

// ===========================================
    int x(6);
    int y(0);
    try{
        int res = (y != 0) ? (x / y) : (throw std::string {"Деление на ноль"});
        std::println("{} / {} = {}", x, y, res);
    }
    catch(const std::string& error_message) {
        std::println("{}", error_message);
    }
}

