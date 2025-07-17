#include <iostream>
#include <string>

struct Date_int {
    bool isDateCorrect;
    int day;
    int month;
    int year;
};

Date_int isDateFormat(std::string& date) {
    Date_int date_correct;
    date_correct.isDateCorrect = true;
    bool& isDateCorrect = date_correct.isDateCorrect;
    if(date.find('.') == std::string::npos) {
        isDateCorrect = false;
        return date_correct;
    }
    date_correct.day = 0;
    int& dd {date_correct.day};   
    try {
        dd = stoi(date.substr(0, date.find('.')));
    } catch (const std::invalid_argument& e) {
        isDateCorrect = false;        
        return date_correct;
    } catch (const std::out_of_range& e) {
        isDateCorrect = false;        
        return date_correct;
    }
    if(date.find('.') == 1) {
        date.insert(0, "0");
    } else if (date.find('.') > 2){
        isDateCorrect = false;
        return date_correct;
    }
    if(dd > 31 || dd < 1) {
        isDateCorrect = false;
        return date_correct;
    }        

    date_correct.month = 0;
    int& mm {date_correct.month};
    if(date.find('.', 3) == std::string::npos) {
            isDateCorrect = false;
            return date_correct;
    } else {
        try {
            mm = stoi(date.substr(3, date.find('.', 3) - 3));
        } catch(const std::invalid_argument& e) {
            isDateCorrect = false;
            return date_correct;
        } catch(const std::out_of_range& e) {
            isDateCorrect = false;
            return date_correct;
        }
        if(mm > 12 || mm < 1) {
            isDateCorrect = false;
            return date_correct;
        } else if(mm > 0 && mm < 10 && date.find('.', 3) == 4) {
            date.insert(3, "0");
        }
    }
    if((date.substr(6)).size() == 2) {
        date.insert(6, "20");
    } else if((date.substr(6)).size() != 2 && (date.substr(6)).size() != 4) {
        isDateCorrect = false;
        return date_correct;
    }
    date_correct.year = 0;
    int& yyyy {date_correct.year};
    try {
        yyyy = stoi((date.substr(6)));
    } catch(const std::invalid_argument& e) {
        isDateCorrect = false;
        return date_correct;
    } catch(const std::out_of_range& e) {
        isDateCorrect = false;
        return date_correct;
    }
    bool leap = (yyyy % 400 == 0) || ((yyyy % 4 == 0) && (yyyy % 100 != 0));
    if(((mm == 2) && ((leap && dd > 29) || (!leap && dd > 28)))
        || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31)) {
            isDateCorrect = false;
            return date_correct;
    }
    return date_correct;
}

void get_correct_date(Date_int& date_correct) {
    std::string date {""};
    std::cout << "Enter the date in the format dd.mm.yyyy--> ";
    std::cin >> date;
    while(!isDateFormat(date).isDateCorrect) {
        std::cout << "Enter correct date please -->  ";
        std::cin >> date;
    }
    date_correct = isDateFormat(date);
}

void printResult(Date_int& date_correct) {
    std::cout << "Birtsday: "
              << date_correct.day << "."
              << date_correct.month << "."
              << date_correct.year << "\n";
}

int main() {
    Date_int birtsday {};
    std::cout.setf(std::ios::boolalpha); // для булевых переменных
    get_correct_date(birtsday);
    printResult(birtsday);   
    std::cout << 2025 - birtsday.year << "\n";
    std::cout << "Game over.\n";
}
