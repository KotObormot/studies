#include <iostream>
#include <thread>
#include <chrono>

int main() {
    int seconds = 0;

    std::cout << "Секундомер запущен. Нажмите Ctrl+C для остановки." << std::endl;

    while (true) {
        std::cout << "\rСекунд: " << seconds++ << "  "; // \r возвращает курсор в начало строки
        std::cout.flush(); // Обновляем вывод
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка на 1 секунду
    }

    return 0;
}
