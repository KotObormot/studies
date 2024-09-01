//https://radioprog.ru/post/1153
//пример калькулятора с полной проверкой ошибок при вводе:
#include <iostream>
#include <limits>
 
void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
 
double getDouble()
{
    while (true) // Цикл, пока пользователь не введет допустимые данные
    {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;
 
        // Проверяем на неудачное извлечение
        if (std::cin.fail()) // предыдущее извлечение не удалось?
        {
            // да, давайте разберемся с ошибкой
            std::cin.clear(); // возвращаем нас в "нормальный" режим работы
            ignoreLine();     // и удаляем неверные входные данные
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine(); // удаляем любые посторонние входные данные
 
            // пользователь не может ввести бессмысленное значение double,
            // поэтому нам не нужно беспокоиться о его проверке
            return x;
        }
    }
}
 
char getOperator()
{
    while (true) // Цикл, пока пользователь не введет допустимые данные
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;
        ignoreLine();
 
        // Проверяем, ввел ли пользователь осмысленные данные
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // возвращаем символ вызывающей функции
        default: // в противном случае сообщаем пользователю, что пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    } // и попробуем еще раз
}
 
void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Надежность означает также обработку неожиданных параметров,
             // даже если getOperator() гарантирует, что op в этой
             // конкретной программе корректен 
        std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}
 
int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };
 
    printResult(x, operation, y);
 
    return 0;
}
