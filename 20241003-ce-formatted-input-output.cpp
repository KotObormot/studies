#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits> // для std::numeric_limits

int main() {
    std::vector<std::string> name_owner;
    std::string owner {};
    for(int i = 0; i < 3; ++i) {
        std::cout << "--> ";
        std::cin >> owner;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //owner.resize(12);
        name_owner.push_back(owner);
    }
    
    for(int i = 0; i < size(name_owner); ++i) {
    std::cout << std::setw(20) << name_owner[i]
              << ": " << std::setw(3) << i << "\n"
              ;
    }
}
