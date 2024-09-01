//cin_excp генератор исключений
#include <ios>
#include <iostream>
//#include <exception>
//
bool cin_excp(int& intInp) {
    std::cin.exceptions(std::ios_base::failbit);
    bool isCrrctInt {true};
    //int sum = 0;
    try {
        /*while(std::cin >> intInp)*/
       if() {
            //sum += intInp;
            return isCrrctInt;
        }
   
    } catch(std::ios_base::failure & bf) {
        //std::cout << bf.what() << std::endl;
        //std::cout << "O! The horror";
        isCrrctInt = false;
        //return isCrrctInt;
    }
   
    //std::cout << "Last " << intInp << std::endl;
    //std::cout << "Sum " << sum << std::endl;    
    return isCrrctInt;
} 

int main() {
    int reqAmount;
   // int sum{0};
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Enter the required amount of cash with an accuracy of 100 rubles--> ";    
   // std::cin >> reqAmount;
        // std::cout << cin_excp(reqAmount) << "\n";
       while (cin_excp(reqAmount)) { 
                 
             while( reqAmount % 100 != 0) {
                 std::cout << "Input error. Please enter a number that is a multiple of 100-->";
                std::cin >> reqAmount;
        //std::cout << cin_excp(reqAmount) << "\n";        
                   
             }
       }
//std::cin.get(reqAmount);
    
//    while(reqAmount % 100 != 0) {        
//        std::cout << "The amount must be a multiple of 100--> ";
//        std::cin >> reqAmount;
//    }
}
