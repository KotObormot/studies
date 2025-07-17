//https://metanit.com/cpp/tutorial/5.9.php
//Перечисления

#include <iostream>

enum Months { //перечисление в С-style, они называются unscoped , не рекомендуется
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Nov,
    Dec
};

enum class Day { //по умолчанию int
    Monday = 1,
    Mon = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
//using enum Day; expected an identifier , до С++20 не работает
enum class Operation: char {
    Add = '+',
    Subtract = '-',
    Multiply = '*',
    Division = '/'
};

void calculate(int n1, int n2, Operation op) {
    std::cout << n1 << " " << static_cast<char>(op)
              << " " << n2 << " = ";
    switch (op) {        
        case Operation::Add: 
            std::cout << n1 + n2 << std::endl;
            break;
        case Operation::Subtract:
            std::cout << n1 - n2 << std::endl;
            break;
        case Operation::Multiply:
            std::cout << n1 * n2 << std::endl;
            break;
        case Operation::Division:
            std::cout << n1 / n2 << "\n";
    }
}

int main() {
    Months nowadays = Sep;
    std::cout << "Сейчас идет " << nowadays << "-й месяц\n";
    /*-----------------------------------------------------------------*/

    Day today = Day::Thursday;
    //Day today {Day::Thursday};

    //std::cout << today << " : "; no operator "<<" matches these operandsC
    std::cout << "Today: " <<  static_cast<int>(today) << "\n";
    /**************************************************************** */
    /*std::cout << "add: " << static_cast<char>(Operation::Add) << std::endl;
    std::cout << "subtracte: " << static_cast<char>(Operation::Subtract) << std::endl;
    std::cout << "multiply: " << static_cast<char>(Operation::Multiply) << std::endl;
    std::cout << "division: " << static_cast<char>(Operation::Division) << "\n";*/

    calculate(10, 6, Operation::Add);           // 16
    calculate(10, 6, Operation::Subtract);      // 4
    calculate(10, 6, Operation::Multiply);      // 60
    calculate(10, 5, Operation::Division);      // 2
}