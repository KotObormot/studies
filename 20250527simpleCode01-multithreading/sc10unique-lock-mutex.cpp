#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
//#include <SimpleTimer.h>

std::mutex mtx;

void Print(char ch) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::unique_lock<std::mutex> ul(mtx);

    for(int i(0); i < 5; ++i) {
        for(int j(0); j < 10; ++j) {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
    ul.unlock();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
    std::cout << "Hello!\n";
    //std::cout << std::thread::hardware_concurrency() << "\n";
    std::cout << "START MAIN\n";

    std::thread t1(Print, '*');
    std::thread t2(Print, '#');

    t1.join();
    t2.join();

    std::cout << "FINISH MAIN\n";

}
// https://www.youtube.com/watch?v=2ysGNxsKlxk&list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0&index=10&t=36s
/*
Обзор от ИИ
std::unique_lock в C++ - это класс-оболочка для управления мьютексами (mutexes), который обеспечивает более гибкий и безопасный способ владения мьютексом, чем std::lock_guard. Он предоставляет отложенную блокировку, ограниченные по времени попытки блокировки, возможность передачи владения мьютексом и интеграцию с условными переменными (condition variables). 
Вот основные характеристики и возможности std::unique_lock:

    Автоматическое управление блокировкой:
    При создании объекта std::unique_lock он автоматически пытается захватить мьютекс. При выходе объекта из области видимости (например, при завершении блока кода) мьютекс автоматически освобождается, даже если происходит исключение. 

Отложенная блокировка:
В отличие от std::lock_guard, std::unique_lock позволяет отложить блокировку мьютекса до момента, когда это необходимо. Это достигается с помощью конструктора без аргументов или с помощью функции lock(). 
Ограниченные по времени попытки блокировки:
std::unique_lock может использоваться для попытки захвата мьютекса с ограничением по времени, что полезно для предотвращения взаимных блокировок (deadlocks). 
Передача владения:
Владение мьютексом может быть передано между объектами std::unique_lock с помощью операции перемещения (move semantics), что полезно при передаче владения мьютексом между функциями. 
Поддержка условных переменных:
std::unique_lock тесно интегрирован с условными переменными (condition variables), что позволяет эффективно управлять доступом к разделяемым данным в многопоточной среде. 
Ручная блокировка и разблокировка:
std::unique_lock позволяет вручную блокировать и разблокировать мьютекс, что дает больше контроля над синхронизацией. 

В целом, std::unique_lock предоставляет более гибкий и функциональный способ управления мьютексами по сравнению с std::lock_guard, но требует более внимательного использования, чтобы избежать ошибок. 
*/