#include <iostream>

int main() {
    int n, k;
    do{
        std::cout << "Enter the length of the stairs (> 0) --> ";
        std::cin >> n;
    }
    while(n <= 0);
    std::cout << "The bunny needs to climb up to " << n << " step.\n";
    
    std::cout << "The default bunny hop length is 3. Would you like to enter a different value? --> ";
    std::cin >> k;
    k = k > 0 ? k : 3;
    std::cout << "Bunny jump length " << k << " steps.\n";
}

