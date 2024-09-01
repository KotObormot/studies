#include <iostream>
#include <vector>
//#include <cstlib>
#include <ctime>

int main() {
    int n = 5, m = 5;
    std::srand(std::time(nullptr));
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            a[i][j] = std::rand() % 2;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cout << a[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
