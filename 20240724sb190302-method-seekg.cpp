#include <fstream>
#include <iostream>

int main() {
    std::ifstream bank;
    std::string sourceFile;
    std::cout << "source file --> ";
    std::cin >> sourceFile;
    bank.open("../studies-data/" + sourceFile, std::ios::binary);
    char buffer[20];

    bank.read(buffer, sizeof(buffer));
    buffer[19] = 0;
    std::cout << "1) " << buffer << "\n";
    bank.read(buffer, sizeof(buffer));
    buffer[19] = 0;
    std::cout << "2) " << buffer << ".\n";
    
    bank.seekg(0);

    bank.read(buffer, sizeof(buffer));
    buffer[19] = 0;
    std::cout << "3) " << buffer << "\n";
    
    bank.seekg(10);
    std::cout << bank.tellg() << " -->>";

    bank.read(buffer, sizeof(buffer));
    buffer[19] = 0;
    std::cout << "4) " << buffer << "\n";

    bank.close();
}

