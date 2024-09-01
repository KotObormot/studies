#include <fstream>
#include <iostream>
//#include <cstlib> // для random

int main() {
    int control_sum {0};
    int buildings[1000];
    for(int i = 0; i < std::size(buildings); ++i) {
        buildings[i] = std::rand() % 51; //массив заполняем случайными числами
        control_sum += buildings[i];
    }
    std::ofstream file("./data/buildings2004.txt");
    for(int i = 0; i < std::size(buildings); ++i) {
        file << buildings[i] << "\n";
    }
   
    std::cout << control_sum << "\n"; 
    file.close();

    int control_in_sum {0};
    std::ifstream in_file("./data/buildings2004.txt");
    int in_buildings[1000];
    for(int i = 0; i < std::size(in_buildings); ++i) {
        in_file >> in_buildings[i];
        control_in_sum += in_buildings[i];
    }

    in_file.close();
    std::cout << control_in_sum << "\n";
}
