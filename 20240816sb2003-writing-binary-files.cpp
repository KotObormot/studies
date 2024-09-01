#include <fstream>
#include <iostream>
#include <cstring> // для strlen

int main() {
    int number;
    std::cout << "Enter number -->";
    std::cin >> number;

    std::ofstream file("./data/number2003.bin", std::ios::binary);
    file.write((char*)&number, sizeof(number));
    file.close();

    int control_number;
    std::ifstream user_file("./data/number2003.bin", std::ios::binary);
    user_file.read((char*)&control_number, sizeof(control_number));
    user_file.close();

    int user_number;
    std::cout << "Enter the number you want--> ";
    std::cin >> user_number;

    if(user_number == control_number) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose! Correct answer " << control_number << "\n";
    }

    char title[] {"Skillbox"};
    std::ofstream title_bin("./data/title2003.bin", std::ios::binary);
    title_bin.write(title, std::strlen(title));
    title_bin << "-" << 20;
    title_bin.close();
}
