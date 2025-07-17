#include <iostream>
#include <string>
//#include <cstdlib>

bool isDateFormat(std::string& date) {
    bool isDateCorrect {true};
    if(date.find('.') == std::string::npos) {
// Если строка или символ не найдены, то возвращается специальная константа std::string::npos, 
        isDateCorrect = false;
        //std::cerr << "Not found\n";
        return isDateCorrect;
    }
    //std::cout << ".posDD= " << date.find('.') << "\n";
    int dd {0};    
    try {
        dd = stoi(date.substr(0, date.find('.')));
//        std::cout << stoi(date.substr(0, date.find('.'))) << " " << dd << "\n";
    } catch (const std::invalid_argument& e) {
        isDateCorrect = false;        
        return isDateCorrect;
    } catch (const std::out_of_range& e) {
        isDateCorrect = false;        
        return isDateCorrect;
    }
    //std::cout << dd << "\n";    
    if(date.find('.') == 1) {
        date.insert(0, "0");
    } else if (date.find('.') > 2){
        isDateCorrect = false;
        return isDateCorrect;
    }
    if(dd > 31) {
        isDateCorrect = false;
        return isDateCorrect;
    }        
     
//    std::cout << "DD = " << dd << " " << isDateCorrect << "\n";

    int mm {0};
    if(date.find('.', 3) == std::string::npos) {
            isDateCorrect = false;
            std::cerr << "Not found\n";
            return isDateCorrect;
    } else {
        //std::cout << ".posMM= " << date.find('.', 3) << "\n";
        //std::cout << date.substr(3, date.find('.', 3) - 3) << "\n";
        try {
            mm = stoi(date.substr(3, date.find('.', 3) - 3));
        } catch(const std::invalid_argument& e) {
            isDateCorrect = false;
            return isDateCorrect;
        } catch(const std::out_of_range& e) {
            isDateCorrect = false;
            return isDateCorrect;
        }
        //std::cout << mm << "\n";
        if(mm > 12) {
            isDateCorrect = false;
            return isDateCorrect;
        } else if(mm > 0 && mm < 10 && date.find('.', 3) == 4) {
            date.insert(3, "0");
        }
    }
//    std::cout << "MM " << isDateCorrect << "\n";

    if((date.substr(6)).size() == 2) {
        date.insert(6, "20");
    } else if((date.substr(6)).size() != 2 && (date.substr(6)).size() != 4) {
        isDateCorrect = false;
        return isDateCorrect;
    }
//    std::cout << date << "\n";
    
    int yyyy {0};
    try {
        yyyy = stoi((date.substr(6)));
    } catch(const std::invalid_argument& e) {
        isDateCorrect = false;
        return isDateCorrect;
    } catch(const std::out_of_range& e) {
        isDateCorrect = false;
        return isDateCorrect;
    }
    bool leap = (yyyy % 400 == 0) || ((yyyy % 4 == 0) && (yyyy % 100 != 0));

//    std::cout << leap << "\n";
//    std::cout << dd << " " << mm << " " << yyyy << "\n";    
    
//    bool boolFeb = (mm == 2) && ((leap && dd > 29) || (!leap && dd > 28));
//    std::cout << "Feb = " << boolFeb << "\n";

//    bool bool3 = ((mm == 4 || mm == 6 || mm == 9 || mm == 11) &&dd == 31);
//    std::cout << "3) " << bool3 << "\n";

    if(((mm == 2) && ((leap && dd > 29) || (!leap && dd > 28)))
        || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31)) {
            isDateCorrect = false;
            return isDateCorrect;
    }
    return isDateCorrect;
}

void get_correct_date(std::string& date) {
    std::cout << "Enter the date in the format dd.mm.yyyy or 0--> ";
    std::cin >> date;
    //while(!isDateFormat(date)) {
    //    std::cout << "Enter correct date please -->  ";
    //    std::cin >> date;
    //}

    while(true) {
        if(!isDateFormat(date)) {
            std::cout << "Enter correct date please dd.mm.yyy--> ";
            std::cin >> date;
        } else if(date == "0") {
            std::cout << "Game over.\n"; 
            return;
        }
    }    
    if(isDateFormat(date)) {
        std::cout << "Correct date: " << date << "\n";
    } else {
        std::cerr << "Incorrect date.\n";
    }
}

int main() {
    //std::cout.setf(std::ios::boolalpha); // для булевых переменных
    bool gameOver {true};
    std::string date{""};
    while(gameOver) {
        get_correct_date(date);
        std::cout << "To end input, enter 0--> ";
        std::cin >> gameOver;
    }
    std::cout << "Game over.\n";
}
