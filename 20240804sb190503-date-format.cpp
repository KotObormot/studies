#include <iostream>
#include <string>

int main() {
    std::string date = {"01.1.2020"};
    if(date.find('.') == std::string::npos) {
// Если строка или символ не найдены (как в примере выше в последнем случае), то возвращается специальная константа std::string::npos, 
        std::cout << "Not found\n";
    }
    
    if(date.find('.') == 1) {
        date.insert(0, "0");
    }  
    
    if(date.find('.', 3) == 4) {
        date.insert(3, "0");
    }
    
    date.erase(10);

    std::cout << date << "\n";
}
