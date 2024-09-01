#include <iostream>

void bubblesort(float *lft, float *rght) {
	int smllstSize = rght - lft;
    std::cout << smllstSize << "\n";
	if (smllstSize <= 1) return;
	bool isSearchOver = true;
	while (isSearchOver) {
		isSearchOver = false;
		for (float *i = lft; i + 1 <= rght; i++) {            
			if (*i < *(i + 1)) { 
                std::swap(*i, *(i + 1));
				isSearchOver = true;
			}            
		}        
		rght--;         
	}
    return;
}

int main() {
    int arraySize {6};
   // std::cout << "Enter an array size: ";
   // std::cin >> arraySize;
    float fractionalNumbers[] {100, 200, 500, 1000, 2000, 5000};
    //std::cout << "Enter " << arraySize << " fractional numbers: ";
    //for(int i = 0; i < arraySize; ++i) {
    //    std::cin >> fractionalNumbers[i];
    //}

    bubblesort(&fractionalNumbers[0], &fractionalNumbers[0] + arraySize - 1);   
    
    std::cout << "\n" << "Final array:  ";
    for(int i = 0; i < arraySize; ++i) {
        std::cout << fractionalNumbers[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
