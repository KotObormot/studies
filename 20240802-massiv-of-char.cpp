//
#include <iostream>

int main() {
    char dd[] = "12";
    std::cout << dd << " " << sizeof(dd) << "\n";
    for(int i = 0; i < sizeof(dd); ++i) {
        std::cout << dd[i] << " % ";
    }
    std::cout << "\n";
    
    char mm[] = "01";
    char yyyy[] = "2024";

    std::string date1 = dd + '.' + mm + '.' + yyyy;
    std::cout << date1 << "\n";    
}
