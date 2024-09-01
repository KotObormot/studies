#include <iostream>

int main() {
    int arraySize;
    std::cout << "Enter an array size: ";
    std::cin >> arraySize;
    float fractionalNumbers[arraySize];
    std::cout << "Enter " << arraySize << " fractional numbers: ";
    for(int i = 0; i < arraySize; ++i) {
        std::cin >> fractionalNumbers[i];
    }

    std::cout  << "Source array: {";
    for(int j = 0; j < arraySize; ++j) {
        std::cout << fractionalNumbers[j] << ", ";
    }
    std::cout << "}\n";   

    /*===============Bubble sort=======================*/
    int finalPos = arraySize;
    int startPos = 0;
    bool isSearchOn = true;
    bool isSortingCompleted = false;
    while(isSearchOn && !isSortingCompleted) {
        isSearchOn = false;
        std::cout << finalPos << ") " ;
        std::cout << "{ ";
        for(int i = 0; i + 1 < finalPos; ++i) {
            if(fractionalNumbers[i] < fractionalNumbers[i + 1]) {
                std::swap(fractionalNumbers[i], fractionalNumbers[i + 1]);
                std::cout << fractionalNumbers[i] << ", ";
                isSearchOn = true;
            } else {                
                continue;
            }            
        }
        std::cout << "} ";
        for(int i = finalPos - 1; i < arraySize; ++i) {
            std::cout << fractionalNumbers[i] << " > ";  
        }
        --finalPos;
        std::cout << "\n";
        isSortingCompleted = finalPos == 0;
    }
    /*************end of Bubble sort********************/   

    std::cout << "\n" << "Final array: {";
    for(int i = 0; i < arraySize; ++i) {
        std::cout << fractionalNumbers[i] << ", ";
    }
    std::cout << "}\n";
}
