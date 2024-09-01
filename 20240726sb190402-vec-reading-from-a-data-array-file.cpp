#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream bank;
    std::string sourceFile;
    std::cout << "source file --> ";
    /*while(!bank.is_open()) {
        std::cin >> sourceFile;*/
        bank.open("./data/bank2.txt");
        if(!bank.is_open()) {
            std::cerr << "Error opening file. Please type the correct file name --> ";
        } else {
            std::cout << "File opened.\n";
        }
   /*}*/
    std::vector<double> purse; // максимально возможное число элементов массива неизвестно
    double sum = 0;
    while(!bank.eof()) {
        std::cout << !bank.eof() << ":";
        double money = 0;
        bank >> money;
        purse.push_back(money);
        std::cout << !bank.eof() << "%";
    }
    std::cout << "\n";
    
    for(int i = 0; i < purse.size(); ++i) {
        std::cout << purse[i] << " ";
        sum += purse[i];
    }
    std::cout << "\n";
    std::cout << purse.size() << "\n";
    std::cout << "Sum: " << sum  << "\n";

    bank.close();
}

