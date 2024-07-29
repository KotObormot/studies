#include <iostream>
int numbers[] = {32, 65, 11, 23, 8129, 12, 13};
const char* name = "README.txt";
const char* path = "../studies/README.txt";
int main() {
    std::cout << numbers << " " << &numbers << " " << numbers[5] << "\n";
    std::cout << name << " " << &name << " " << *name << " " << name[4] << "\n";
    std::cout << path << " " << &path << " " << *path << " " << path[4] << "\n";
}
