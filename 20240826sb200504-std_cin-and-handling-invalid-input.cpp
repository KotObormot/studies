//паодготовительный материал на основе:
//https://radioprog.ru/post/1153
//пример калькулятора с полной проверкой ошибок при вводе:
#include <iostream>
#include <limits>
 
void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
 
int handling_invalid_input()
{
    while (true) // Цикл, пока пользователь не введет допустимые данные
    {
        std::cout << "-->  ";
        int x{0};
        std::cin >> x; 
        // Проверяем на неудачное извлечение
        if (std::cin.fail()) { // предыдущее извлечение не удалось?        
            // да, давайте разберемся с ошибкой
            std::cin.clear(); // возвращаем нас в "нормальный" режим работы
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;     // и удаляем неверные входные данные
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');; // удаляем любые посторонние входные данные
            return x;
        }
    }
}
 

