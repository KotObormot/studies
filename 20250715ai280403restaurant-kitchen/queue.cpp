#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    std::cout << "Размер очереди: " << myQueue.size() << std::endl; // Вывод: 3

    while (!myQueue.empty()) {
        std::cout << "Передний элемент: " << myQueue.front() << std::endl; // Вывод: 10, 20, 30
        myQueue.pop();
    }

    std::cout << "Размер очереди после извлечения всех элементов: " << myQueue.size() << std::endl; // Вывод: 0

    return 0;
}