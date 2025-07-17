#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <cstdlib> // для std::numeric_limits

int main() {
    std::cout << "Hello\n";
    std::srand(std::time(nullptr));
    /*std::string nm {""};
    for (int j = 0; j < ((std::rand() % 7) + 6); ++j) {
        char letter = (char)((std::rand() % 26) + 65);
        nm.push_back(letter);
    }
    std::cout << "\n======= " << nm << " ============\n";
    std::ofstream vllg("./data/village.bin", std::ios::out | std::ios::app | std::ios::binary);
    int len = nm.length();
    vllg.write((char*)& len, sizeof(nm));
    vllg.write(nm.c_str(), len);
    vllg.close();*/

    std::string nmr {""};
    std::ifstream vllgr("./data/village.bin", std::ios::in | std::ios::binary);
    if(!vllgr.is_open()) {
        std::cerr << "The village is missing. Please plan. ";
        return 1;
    } else {
        while(!vllgr.eof()) {
            int len;
            vllgr.read((char*)& len, sizeof(len));
            std::cout << "len = ! " << (char*)& len << " !! " << len << "\n";
            nmr.resize(len);
            vllgr.read((char*) nmr.c_str(), len);
        }
    }
    vllgr.close();
    std::cout << "\n************" <<  nmr << " ******************\n";
}



