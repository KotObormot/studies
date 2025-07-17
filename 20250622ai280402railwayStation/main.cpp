#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <string>
#include <chrono>

struct Train {
    std::string name;
    int travel_time; // время в пути в секундах
    bool arrived = false; // прибыл ли поезд
    bool on_platform = false; // на перроне
    bool departed = false; // уехал ли поезд
};

std::mutex mtx;
std::condition_variable cv;
bool platform_free = true; // есть ли свободный перрон

std::vector<Train> trains;
int trains_left = 3;

/*
void train_arrival(int index) {
    int t = trains[index].travel_time;
    std::this_thread::sleep_for(std::chrono::seconds(t));
    {
        std::unique_lock<std::mutex> lock(mtx);
        trains[index].arrived = true;
        std::cout << "Поезд " << trains[index].name << " прибыл на вокзал.\n";

        // Если перрон занят, выводим сообщение о ожидании
        while (!platform_free) {
            std::cout << "Поезд " << trains[index].name << " ожидает освобождения перрона.\n";
            cv.wait(lock);
        }
        // Захватываем перрон
        platform_free = false;
        trains[index].on_platform = true;
        std::cout << "Поезд " << trains[index].name << " занял перрон.\n";
    }
}
*/

void train_thread(int index) {
//    train_arrival(index);
    int t = trains[index].travel_time;
    std::this_thread::sleep_for(std::chrono::seconds(t));
    {
        std::unique_lock<std::mutex> lock(mtx);
        trains[index].arrived = true;
        std::cout << "Поезд " << trains[index].name << " прибыл на вокзал.\n";

        // Если перрон занят, выводим сообщение о ожидании
        while (!platform_free) {
            std::cout << "Поезд " << trains[index].name << " ожидает освобождения перрона.\n";
            cv.wait(lock);
        }
        // Захватываем перрон
        platform_free = false;
        trains[index].on_platform = true;
        std::cout << "Поезд " << trains[index].name << " занял перрон.\n";
    }

    // После прибытия ждет команды depart для отправления
    while (true) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (trains[index].departed) {
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void command_handler() {
    while (true) {
        if (trains_left == 0) break;

        std::string cmd;
        if (!std::getline(std::cin, cmd)) break;
        
        if (cmd == "depart") {
            std::unique_lock<std::mutex> lock(mtx);
            bool found_train = false;
            for (int i=0; i<trains.size(); ++i) {
                if (trains[i].arrived && !trains[i].departed && trains[i].on_platform) {
                    // Отправляем этот поезд
                    trains[i].departed = true;
                    trains[i].on_platform = false;
                    trains_left--;
                    platform_free = true;
                    std::cout << "Поезд " << trains[i].name << " уезжает с вокзала.\n";
                    cv.notify_all();
                    found_train = true;
                    break;
                }
            }
            if (!found_train) {
                std::cout << "Нет поезда на перроне для отправления.\n";
            }
            if (trains_left == 0) break;
        } else {
            std::cout << "Неизвестная команда. Используйте 'depart'.\n";
        }
    }
}

int main() {
    for (int i=0; i<3; ++i) {
        int t;
        std::cout << "Введите время в пути для поезда " << i+1 << " (в секундах): ";
        std::cin >> t;
        std::cin.ignore();
        trains.push_back({"Train" + std::to_string(i+1), t});
    }

    std::vector<std::thread> threads;
    for (int i=0; i<3; ++i) {
        threads.emplace_back(train_thread, i);
    }

    std::thread cmd_thread(command_handler);

    if (cmd_thread.joinable()) cmd_thread.join();

    for (auto& th : threads) {
        if (th.joinable()) th.join();
    }

    std::cout << "Все поезда отбыли. Работа программы завершена.\n";

    return 0;
}