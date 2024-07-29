#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream textToView;
    std::string pathToText = "../data/Tom_Hanks.txt";
    //std::cout << "Specify the path to the file --> ";
    while(!textToView.is_open()) {
       // std::cin >> pathToText;
        textToView.open(pathToText, std::ios::binary);
        if (!textToView.is_open()) {
            std::cerr << "Error opening file! Please type the correct path --> ";
        } else {
            std::cout << "File opened.\n=============================\n";
        }
    }

    int count = 1103;

    while(!textToView.eof() && count < 1850) {
        textToView.seekg(count, std::ios::beg);
        char buffer[20] = {};
        std::cout << "\n" << textToView.gcount() << " % " << textToView.tellg() << "\n";
        textToView.get(buffer, 20);
        // buffer[19] = 0; лишняя операция, т.к. i19 = '\0'
        std::cout << buffer;
        count += 19;
    }
    
    std::cout << "\n=============================\n";
        
    textToView.close();
}
