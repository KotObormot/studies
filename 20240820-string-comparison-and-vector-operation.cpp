#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str1 {"abcd"};
    std::string str2 {"abcd"};

    if(!str1.compare(str2)) {
        std::cout << "OK\n";
    } else {
        std::cout << "No\n";
    }
    
    std::vector<std::string> river {"sunfish", "shad", "carp", "bass", "bullhead", "carp", "walleye", "catfish", "carp"};
    std::vector<std::string> basket;
    std::cout << river.empty() << " " << basket.empty() << "\n";
    std::string fish;
    std::cout << "--> ";
    std::cin >> fish;
    for(int i = 0; i < river.size(); ++i) {
        if(!river[i].compare(fish)) {
            basket.push_back(fish);
        }
    }
     for(int i = 0; i < basket.size(); ++i) {
        std::cout << basket[i] << "\n";
     }
     std::cout << "\n";

    std::cout << "Удаление заданного элемента вектора:\n";
    std::vector<std::string> river1 {"sunfish", "shad", "carp","bass", "bullhead", "carp", "walleye", "catfish", "carp"};
//     std::erase(river1, "carp"); Начиная с С++20
     
    auto iter = river1.cbegin();
    for(int i = 0; i < river1.size(); ++i) {
        if(!river1[i].compare(fish)) {
            river1.erase(iter + i);
        }        
    }
    for(int i = 0; i < river1.size(); ++i) {
        std::cout << i << ") " << river1[i] << "\n";
    }    
    std::cout << "\n";
}
