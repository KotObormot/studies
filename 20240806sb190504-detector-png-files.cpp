//
#include <fstream>
#include <iostream>

int main() {
    std::ifstream pngImageFile;
    std::string pathToImage {"../skillbox18/data/png-file.png"};
    while(!pngImageFile.is_open()) {
        pngImageFile.open(pathToImage, std::iostream::binary);
        if(!pngImageFile.is_open()) {
            std::cerr << "Error opening file!";
        } else {
            std::cout << "File opened.\n=============================\n";
        }
    }
    if(pathToImage.ends_with(".png") {
        std::cout << "OK\n";
    } else {
        std::cout << "False\n";
    }

    pngImageFile.close();
}

