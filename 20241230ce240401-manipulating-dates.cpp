#include <iostream>
#include <ctime>
#include <iomanip>

#define SAMPLE1 true
#define SAMPLE2 false

int main() {
    std::time_t t_utc = std::time(nullptr);
#if SAMPLE1
    std::cout << "utc time = " << t_utc << ", " 
              << std::asctime(std::gmtime(&t_utc)) << "\n";
    std::tm* t_local = std::localtime(&t_utc);
    std::cout << "Local time 1 = " << std::put_time(t_local, "%e.%m.%Y %H:%M:%S") << "\n";
    std::cout << "Delay, enter ENTER--> ";
    std::cin.get();
    std::time_t t1_utc = std::time(nullptr);
    std::tm* t1_local = std::localtime(&t1_utc);
    std::cout << std::asctime(t1_local);    
    double delay = std::difftime(t1_utc, t_utc);
    std::cout << "Delay = "  << delay << "\n";
    std::time_t future_utc = t1_utc + (std::time_t)delay;
    std::tm* future_local = std::localtime(&future_utc);
    std::cout << "Local time 2" << std::asctime(future_local) << "!\n";
#elif SAMPLE2
    int start = clock(); // засекаем время старта
   // далее фрагмент кода, время работы которого измеряется
    std::cout << "Start = " << start << "\n";
    for(int i = 0; i < 1000; i++) {
	  for(int j = 0; j < 100; j++) {
          std::cout << "";
	  }
   }
   int end = clock(); // засекаем время окончания
   std::cout << "End = " << end << "\n";
   std::cout << "End - Start = " << (end - start) << "\n";
   int t = (end - start) * 1000 / CLOCKS_PER_SEC;// команда CLOCKS_PER_SEC нужна для перевода результата функции clock в секунды
   std::cout << " " << t << " msec"; // вывод результата работы на экран
   std::cin.get(); // ждём нажатия пользователем клавиши
#else
    std::tm past_local = *std::localtime(&t_utc); // Структура Локальное Время
    std::cout << "Past date--> ";
    std::cin >> std::get_time(&past_local, "%Y/%m/%d");
    std::cout << "Past = "  << std::asctime(&past_local);
    std::cout << past_local.tm_mday << "."
              << past_local.tm_mon + 1 << "."
              << past_local.tm_year + 1900 << " "
              << past_local.tm_hour << ":"
              << past_local.tm_min << "\n";

    std::tm* today = std::localtime(&t_utc);
    std::cout << "TODAY = "  << std::asctime(today);
    std::cout << "Age = " << (today->tm_year - past_local.tm_year) << " years.\n";
   //double delta = std::difftime((std::time_t)today, past_local);
#endif
}
