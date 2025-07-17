#include "initial_conditions.h"

//#include "train.h" 
template<typename T> T add(T, T); // прототип функции
template<typename T> T correctInput();

int main() {
//    std::cout << "int: " << add(4, 5) << std::endl; 
//    std::cout << "double: " << add(4.4, 5.5) << std::endl;
//    std::cout << "string: " << add(std::string("hel"), std::string("lo")) << std::endl;
    double x = correctInput();
}

template<typename T> T add(T a, T b) {
    return a + b;
}

template<typename T> T correctInput() {
    while (true) { // Цикл, пока пользователь не введет допустимые данные
        std::cout << "-->  ";
        T x {0};
        std::cin >> x;
        // Проверяем на неудачное извлечение
        if (std::cin.fail()) { // предыдущее извлечение не удалось?        
            // да, давайте разберемся с ошибкой
            std::cin.clear(); // возвращаем нас в "нормальный" режим работы
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // и удаляем неверные входные данные
            std::cout << "Oops, that input is invalid.  Please try again: ";
        }   
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');; // удаляем любые посторонние входные данные
            return x;
        }
    }   
}