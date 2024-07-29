#include <fstream>
#include <iostream>

int main() {
    std::ifstream textToView;
    std::string pathToText = "../skillbox18/data/Tom_Hanks.txt";
    //std::cout << "Specify the path to the file --> ";
    while(!textToView.is_open()) {
        //std::cin >> pathToText;
        textToView.open(pathToText, std::ios::binary);
        if (!textToView.is_open()) {
            std::cerr << "Error opening file! Please type the correct path --> ";
        } else {
            std::cout << "File opened.\n";
        }
    }
char buffer[20];
    
    for(int i = 0; i < 20; ++i) {
        buffer[i] = 'f';
    }
    textToView.seekg(45);
    textToView.getline(buffer, 20);
    /*buffer[19] = 0;*/
    std::cout << "1) " << buffer << "\n";

    for(int i = 0; i < 20; ++i) {
        buffer[i] = 'g';
    }
    textToView.seekg(45);
    textToView.getline(buffer, 20);
    /*buffer[19] = 0;*/
    std::cout << "2) " << buffer << "\n";
    
    textToView.close();
}

