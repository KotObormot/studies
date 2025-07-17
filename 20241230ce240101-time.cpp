#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
//    std::srand(std::time(nullptr);
    std::cout << std::time(nullptr) << " Время в сек по UTC от 01.01.1970\n";
    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t); // Структура Локальное Время
    std::cout << local->tm_hour << " Локальный час.\n";
    std::cout << "Функция вывода локального времени: " << std::asctime(local) << "...и перевод строки.\n";

    std::time_t t1 = 5;
    std::tm* tm_1 = std::localtime(&t1);    
    std::cout << std::put_time(tm_1, "%d.%m.%Y %H:%M:%S, %Z") << "\t"
               /*<< std::asctime(tm_1)*/ << "\n";

    std::time_t t2 = -2209084212;
    std::tm* tm_2 = std::localtime(&t2);
    std::cout << std::put_time(tm_2, "%d.%m.%Y %H:%M:%S, %Z") << "\t"
              /*<< std::asctime(tm_2)*/ << "\n";
}
