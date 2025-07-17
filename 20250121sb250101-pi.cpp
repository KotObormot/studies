#include <cmath>
#include <iostream>
//#include <iomanip>

double pi() {
    return atan(1.0) * 4.0;
}

int main() {
    std::cout << std::fixed << pi() << "\n";
}
