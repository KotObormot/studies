// вращение волчка
//
#include <iostream>

int main() {
    int sectors[13] {};
    int offset;
    int iPos {0};
    std::cout << "The game begins." << "\n";
    while(offset != 100) {
        std::cout << "Spin the whirligig.--> ";
        std::cin >> offset;
        
        iPos = (iPos + offset % 13 >= 13) ? (iPos + offset % 13 - 13) : (iPos + offset % 13);
        std::cout << "%iPos = " << iPos << "\n";      
        
        if(sectors[iPos] != 0) {
            do {
                iPos = (iPos + 1 >= 13) ? (iPos + 1 - 13) : (iPos + 1);
            } 
            while(sectors[iPos] != 0);
        } 
        
        sectors[iPos] = 1;   

        std::cout << "iPos = " << iPos << "\n";
        
    for(int i = 0; i < std::size(sectors); ++i) {
        std::cout << sectors[i];
    }
    std::cout << "\n";
    }
    
    std::cout << "Game over.\n";
}
