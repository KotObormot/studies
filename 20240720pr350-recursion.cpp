#include <iostream>

void countdown(int n);	//объявление функции, а тело - после main

int main() {
        int n;
        std::cout << "Введите уровень рекурсии --> ";
        std::cin >> n;
        countdown(n);   //вызываем рекурсивную функцию
}

void countdown(int n) {
	std::cout << "Counting down.. " << n << " at " << &n << "\n"; //каждый рекурсивный вызов создает отдельную переменную
	if(n > 0) {
		countdown(n - 1);	//функция вызывает самоё себя
	}
	std::cout << n << " at " << &n << ": Kaboom!\n";
}

