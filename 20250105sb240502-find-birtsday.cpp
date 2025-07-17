#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::tm birtsday_get {};
    std::cout << "Birtsday dd.mm.yyyy--> ";
    std::cin >> std::get_time(&birtsday_get, "%d.%m.%Y");
    const std::time_t birtsday = mktime(&birtsday_get);
    std::tm* birtsday_loc = std::localtime(&birtsday);
    int day_brtsdy = birtsday_loc->tm_mday;
    int month_brtsdy = birtsday_loc->tm_mon + 1;
    int year_brtsdy = birtsday_loc->tm_year + 1900;
    std::cout << day_brtsdy << "." << month_brtsdy << "." << year_brtsdy <<  "\n";

    std::cout << "The date you are looking for--> ";
    std::tm date_looking_entered {};
    std::cin >> std::get_time(&date_looking_entered, "%d.%m.%Y");
    const std::time_t date_looking = mktime(&date_looking_entered);
    std::tm* date_local = std::localtime(&date_looking);
    int day_looking = date_local->tm_mday;
    int month_looking = date_local->tm_mon + 1;
    int year_looking = date_local->tm_year + 1900;
    std::cout << day_looking << "." << month_looking << "." << year_looking << "\n";

    if((day_brtsdy == day_looking) && (month_brtsdy == month_looking)) {
        std::cout << (year_looking - year_brtsdy) << " years. Congratulation!\n";
    } else {
        std::cout << "Past\n";
    }
}
