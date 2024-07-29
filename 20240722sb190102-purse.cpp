#include <fstream>
#include <iostream>

int main() {
    std::ifstream bank;
    bank.open("../studies-data/bank.txt"); 
    double money;
    std::string currency;    
    bank >> money >> currency;
    std::cout << money << " " << currency << "\n";
    bank >> money >> currency;
    std::cout << money << " " << currency <<  "\n";
    bank >> money >> currency;
    std::cout << money << " " << currency <<  "\n";
    bank.close();
}
