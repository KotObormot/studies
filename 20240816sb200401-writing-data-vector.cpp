#include <cmath>
#include <fstream>
#include <iostream>
#include <cstdlib> // для random
#include <vector>

int main() {
    int control_sum {0};
    std::vector<int> buildings;
    int count = std::rand() % 901 + 100; //число домов от 100 до 1000
    std::cout << "count = " << count << "\n";
    for(int i = 0; i < count; ++i) {
        buildings.push_back(std::rand() % 51); //вектор заполняем случайными числами
        control_sum += buildings[i];
    }
    //std::cout << std::size(buildings) << " " << buildings.size() << "\n";
    
    std::ofstream file("./data/buildings2004.txt");
    file << count << "\n";
    for(int i = 0; i < buildings.size(); ++i) {
        file << buildings[i] << "\n";
    }
    file << "Skillcity\n";
   
    std::cout << control_sum << "\n"; 
    file.close();

    int control_in_sum {0};
    std::ifstream in_file("./data/buildings2004.txt");
    std::vector<int> in_buildings;
    int in_count;
    in_file >> in_count;
    for(int i = 0; i < in_count; ++i) {
        int in_people;
        in_file >> in_people;
        in_buildings.push_back(in_people);
        control_in_sum += in_buildings[i];
    }
    std::string in_city;
    in_file >> in_city;

    in_file.close();

    if(control_sum == control_in_sum) {
        std::cout << in_city << " population "  << control_in_sum << "\n";
    } else {
        std::cout << "Invalid control sum " <<  control_in_sum << "\n";
    }
}
