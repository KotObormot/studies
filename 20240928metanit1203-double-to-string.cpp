//https://metanit.com/cpp/tutorial/12.3.php
//Преобразование типов и строки
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 

int main() {
    unsigned age{38};
    double age38 {38.0};
    std::string message{ "Age: " + std::to_string(age38)};
    std::cout << message << std::endl;    // Age: 38

    const char* message_ptr = message.c_str();
    std::cout << message_ptr << "\n";

    std::ostringstream ost;
    ost << std::fixed << std::setprecision(1) << age38 << " years";
    std::cout << ost.str() << "\n";
}
