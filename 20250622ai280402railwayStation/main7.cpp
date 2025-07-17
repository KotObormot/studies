#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <string>
#include <atomic>

// Структура для описания поезда
struct Train {
    std::string name;
    int travel_time; // время в пути в секундах
    bool arrived = false; // прибыл ли поезд
    bool on_platform = false; // на перроне
    bool departed = false; // уехал ли поезд
};

// Глобальные переменные для синхронизации
std::mutex mtx;
std::condition_variable cv;
bool platform_free = true; // есть ли свободный перрон
int trains_on_platform = 0; // сколько поездов на перроне (0 или 1)
std::atomic<int> trains_remaining(3); // сколько поездов осталось отправить

// Вектор с поездами
std::vector<Train> trains;

// Функция для имитации прибытия поезда
void train_arrival(int index) {
    int t = trains[index].travel_time;
    std::this_thread::sleep_for(std::chrono::seconds(t));
    {
        std::unique_lock<std::mutex> lock(mtx);
        trains[index].arrived = true;
        std::cout << "Поезд " << trains[index].name << " прибыл на вокзал.\n";

        // Ждем, пока перрон не освободится
        cv.wait(lock, []() { return platform_free; });
        // Захватываем перрон
        platform_free = false;
        trains[index].on_platform = true;
        trains_on_platform++;
        std::cout << "Поезд " << trains[index].name << " занял перрон.\n";
    }
}

// Основная функция потока поезда
void train_process(int index) {
    train_arrival(index);
    // Ждем команды на отправление
    while (true) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (trains[index].departed) {
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    // Уезжаем с вокзала
    {
        std::unique_lock<std::mutex> lock(mtx);
        trains[index].on_platform = false;
        trains[index].departed = true;
        trains_on_platform--;
        platform_free = true;
        std::cout << "Поезд " << trains[index].name << " уезжает с вокзала.\n";
        cv.notify_all();
    }
}

// Обработка команд depart
void command_handler() {
    while (true) {
        if (trains_remaining == 0) break;

        std::string cmd;
        if (!std::getline(std::cin, cmd)) {
            break; // EOF или ввод завершен
        }

        if (cmd == "depart") {
            std::unique_lock<std::mutex> lock(mtx);
            bool sent_train = false;
            for (int i = 0; i < trains.size(); ++i) {
                if (trains[i].arrived && !trains[i].departed && trains[i].on_platform) {
                    // Отправляем этот поезд
                    trains[i].departed = true;
                    trains_on_platform--;
                    platform_free = true;
                    std::cout << "Поезд " << trains[i].name << " уезжает с вокзала.\n";
                    cv.notify_all();
                    sent_train = true;
                    break;
                }
            }
            if (!sent_train) {
                std::cout << "Нет поезда на перроне для отправления.\n";
            }

            // Проверка завершения работы: если все уехали
            int remaining = 0;
            for (const auto& t : trains) {
                if (!t.departed) remaining++;
            }
            if (remaining == 0) break;

        } else {
            std::cout << "Неизвестная команда. Используйте 'depart'.\n";
        }
    }
}

int main() {
    // Ввод времени в пути для каждого из трех поездов
    for (int i = 0; i < 3; ++i) {
        int t;
        std::cout << "Введите время в пути для поезда " << i + 1 << " (в секундах): ";
        std::cin >> t;
        std::cin.ignore(); // очистка буфера после ввода числа
        trains.push_back({"Train" + std::to_string(i + 1), t});
    }

    // Создаем потоки для каждого поезда
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(train_process, i);
    }

    // Запускаем поток обработки команд
    std::thread commandThread(command_handler);

    // Ждем завершения потока командной обработки перед завершением программы
    if (commandThread.joinable()) commandThread.join();

    // Ждем завершения всех потоков поездов
    for (auto& th : threads) {
        if (th.joinable()) th.join();
    }

    std::cout << "Все поезда отбыли. Работа программы завершена.\n";

    return 0;
}