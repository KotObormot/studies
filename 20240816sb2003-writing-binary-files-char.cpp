#include <fstream>
#include <cstring>

int main() {
    char* title = "Skillbox";
    std::ofstream file("./data/title.bin", std::ios::binary);
    file.write(title, std::strlen(title));
    file.close();    
}
