#include <fstream>
#include <iostream>

int main() {
    int money[1000];
    std::ifstream view("./data/money2.bin", std::ios::binary);
    if(view.is_open()) {
        view.read((char*) money, sizeof(money));
        view.close();
    } else {
        std::cerr << "Invalid\n";
    }

    for(int i = 0; i < sizeof(money) / 2; ++i) {
        std::cout << money[i] << " ";
    }
    std::cout << "\n";        
}
