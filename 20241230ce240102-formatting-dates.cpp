#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::time_t t = /*std::time(nullptr)*/-318304677;
    std::tm* gm = std::gmtime(&t); // Структура Локальное Время
    std::cout << std::put_time(gm, "%Y( or %y)/%m/%d %H( or %I):%M:%S, %A(%a)  %B(%b) %Z" ) << "\n";

    std::time_t t1 = (t / 86400) * 86400 - 10800;
    std::tm* local1 = std::localtime(&t1);
    std::cout << std::put_time(local1, "%Y/%m/%d %H:%M:%S, %a %b %Z") << "\n"; 

    int day_b = local1->tm_mday;
    int month_b = local1->tm_mon + 1;
    int year_b = local1->tm_year + 1900;
    std::cout << day_b << "." << month_b << "." << year_b << "\n";
}
