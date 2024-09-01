//cin_excp генератор исключений
#include <ios>
#include <iostream>
//#include <exception>
//

bool isAmountCrcct(int& amount, const int& total_sum) {
    bool isAmountCrcct {false};
    while(amount % 100 == 0 && amount <= total_sum) {
        isAmountCrcct = true;
    }
    return isAmountCrcct;
}

int main() {
    int total_sum {2000};
    int reqAmount;
   // int sum{0};
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Enter the required amount of cash with an accuracy of 100 rubles--> ";    
   // std::cin >> reqAmount;
    
                 std::cout << "Input error. Please enter a number that is a multiple of 100-->";
                std::cin >> reqAmount;
        //std::cout << cin_excp(reqAmount) << "\n";        
             
    std::cin.exceptions(std::ios_base::failbit);
    
    //int sum = 0;
    try {
        /*while(std::cin >> intInp)*/
         {
            //sum += intInp;

        }
   
    } catch(std::ios_base::failure & bf) {
        std::cout << bf.what() << std::endl;
        std::cout << "O! The horror";
        isCrrctInt = false;
        //return isCrrctInt;
    }
   
    //std::cout << "Last " << intInp << std::endl;
    //std::cout << "Sum " << sum << std::endl;    
    
} 

        // std::cout << cin_excp(reqAmount) << "\n";
   //    while (cin_excp(reqAmount)) { 
                 
                   
             
       
//std::cin.get(reqAmount);
    
//    while(reqAmount % 100 != 0) {        
//        std::cout << "The amount must be a multiple of 100--> ";
//        std::cin >> reqAmount;
//    }

