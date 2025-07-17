#include <iostream>
#include <ctime>
//#include <iomanip>
#include <chrono>
#include <termios.h> // for setInputMode & resetInputMode
#include <unistd.h>  // for tcgetattr & tcsetattr

void setInputMode() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag &= ~(ICANON | ECHO); // Отключаем канонический режим и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void resetInputMode() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag |= (ICANON | ECHO); // Включаем канонический режим и эхо
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

int main() {
    setInputMode(); // Устанавливаем режим ввода

    //std::cout << "Секундомер запущен. Нажмите Enter для остановки." ;

    //auto start = std::chrono::steady_clock::now();
    bool running = true;


    std::time_t t_counter = /*std::time(nullptr)*/0;
    //std::cout << std::asctime(std::gmtime(&t_utc)) << "\n";
    //while(true) {
        while(running) {
            // Checking if the Enter key was pressed
            std::tm* tm_counter = std::localtime(&t_counter);
            std::time_t t_start = std::time(nullptr);
            std::tm* tm_start = std::localtime(&t_start);
            int c_start = clock();
            std::cout << "~ ";
            
            while(true) {
                std::time_t t_finish = std::time(nullptr);
                double diffTime = std::difftime(t_finish, t_start);
                int c_finish = clock();    
                if(((int)diffTime >= 1) && ((c_finish - c_start) * 1000 / CLOCKS_PER_SEC) >= 1000) {
                    std::cout << "~ %";
                    //std::cout << std::fixed << diffTime << " sec.\t"
                    //          << (c_finish - c_start) * 1000 / CLOCKS_PER_SEC << " msec.\n";
                    break;
                }
            }

            ++t_counter;
            if(std::cin.peek() == '\n') {
                std::cin.get();   // Read the pressed key
                running = false;  // Stop the stopwatch
            }
    //    }
       //std::cin.get();
       //char finish;
       //std::cin >> finish;
       //if(std::cin.get() == 'f') {
       //if(t_counter > 5) {
       //     break;
       //} //else {
          // continue;
       //}     
    }
    resetInputMode(); // Resetting the input mode
}
