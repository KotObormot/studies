#include <iostream>
#include <ctime>
#include <iomanip>

#define SKILLBOX true

int main() {
#if SKILLBOX
//    std::time_t t = std::time(nullptr);        
//    std::cout << t << "\n";
//    std::tm local = *std::localtime(&t); // Структура Локальное Врем

    std::tm birtsday_get {};
    std::cout << "birtsday dd.mm.yyyy --> ";
    std::cin >> std::get_time(&birtsday_get, "%d.%m.%Y");
    const time_t birtsday = mktime(&birtsday_get);
    std::cout << birtsday << "\n";
    std::tm* birtsday_loc = std::localtime(&birtsday);
    //std::cout << std::asctime(birtsday_loc) << "\n" /*<< (t / 86400) * 86400*/;
    std::cout << std::put_time(birtsday_loc, "%d.%m.%Y") << "\n";
    
    //birtsday += 3 * 3600;
    std::tm* birtsday_gm = std::gmtime(&birtsday);
    //std::cout << std::asctime(birtsday_gm);
    std::cout << std::put_time(birtsday_gm, "%d.%m.%Y") << "\n";
#else
    // https://www.cyberforum.ru/cpp-beginners/thread1909756.html
    std::tm tm_first = {}, tm_second = {};
    std::cout << "Enter two dates with format MM/DD/YY HH:MM:SS\nFirst date: ";
    std::cin >> std::get_time(&tm_first, "%D %T");
    std::cout << "Second date: ";
    std::cin >> std::get_time(&tm_second, "%D %T");  

    std::cout << mktime(&tm_second) << " " << mktime(&tm_first) << "\n";
 
    const time_t diff = mktime(&tm_second) - mktime(&tm_first);

    std::cout << diff << "\n";
    const tm tm_diff = *gmtime(&diff);
 
    std::cout << "\nDiff:\nYears: " << tm_diff.tm_year - 70
        << "\nMonths: " << tm_diff.tm_mon
        << "\nDays: " << tm_diff.tm_mday - 1
        << "\nHours: " << tm_diff.tm_hour
        << "\nMins: " << tm_diff.tm_min
        << "\nSecs: " << tm_diff.tm_sec << std::endl;
#endif
}
