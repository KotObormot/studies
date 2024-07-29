#include <fstream>
#include <iostream>

int main() {
    std::ifstream bank;
    std::string sourceFile;
    std::cout << "source file --> ";
    std::cin >> sourceFile;
    bank.open("./data/" + sourceFile);
    
    double purse[50]; // максимально возможное число элементов массива
    /*bank.read((char*)purse, sizeof(purse));*/
    int count = 0; // текщее число элементов массива
    
    while(!bank.eof()) {
        std::cout << bank.eof() << ":";
        purse[count] = 0;
        bank >> purse[count];
        count++;
        std::cout << bank.eof() << "%";
    }
        
    std::cout << count << "\n";
    for(int i = 0; i < count; ++i) {
        std::cout << purse[i] << " ";
    }
    std::cout << "\n";

    bank.close();
}

