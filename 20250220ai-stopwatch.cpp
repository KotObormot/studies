#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>

void startTimer() {
    int seconds = 0;
    printw("Stopwatch started. Press Enter to stop..\n");

    while (true) {
        printw("\rSeconds: %d  ", seconds++);
        refresh(); // Обновляем вывод
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    initscr(); // Инициализация ncurses
    noecho(); // Не отображать вводимые символы
    cbreak(); // Вход в режим "разбиения" (не буферизовать ввод)

    std::thread timerThread(startTimer);

    // Ожидание нажатия клавиши Enter
    getch(); // Ожидаем нажатия клавиши

    // Остановка таймера
    timerThread.detach(); // Отсоединяем поток, чтобы он завершился
    printw("\nThe stopwatch has stopped.\n");
    refresh();

    // Завершение работы ncurses
    endwin();
    return 0;
}

//g++ -o timer timer.cpp -lncurses -pthread
