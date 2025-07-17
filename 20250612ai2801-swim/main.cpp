#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <algorithm>

struct Swimmer {
    std::string name;
    double speed; // метров в секунду
    double distance = 0.0;
    double time_taken = 0.0; // время завершения заплыва
    bool finished = false;
};

std::mutex mtx; // мьютекс для синхронизации вывода и обновления данных

void swim(Swimmer& swimmer, double race_distance) {
    auto start_time = std::chrono::steady_clock::now();
    while (swimmer.distance < race_distance) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(mtx);
            swimmer.distance += swimmer.speed;
            if (swimmer.distance >= race_distance) {
                swimmer.distance = race_distance;
                auto end_time = std::chrono::steady_clock::now();
                swimmer.time_taken = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
                swimmer.finished = true;
            }
        }
    }
}

int main() {
    const double race_distance = 100.0; // 100 метров
    std::vector<Swimmer> swimmers = {
        {"Алексей", 2.5},
        {"Мария", 2.8},
        {"Иван", 2.3},
        {"Елена", 2.6},
        {"Дмитрий", 2.4},
        {"Ольга", 2.7}
    };

    // Запускаем потоки для каждого пловца
    std::vector<std::thread> threads;
    for (auto& swimmer : swimmers) {
        threads.emplace_back(swim, std::ref(swimmer), race_distance);
        //std::thread oneThread(swim, std::ref(swimmer), race_distance);
        //threads.push_back(oneThread);
    }

    bool all_finished = false;
    int timePassed(0);
    while (!all_finished) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            // Выводим прогресс
//            system("clear"); // для Linux, очищает экран
            std::cout << "===========Заплыв 100 метров:\t" << timePassed << " sec\n";
            for (const auto& swimmer : swimmers) {
                std::cout << "\t"
                          << std::setw(10) << swimmer.name << " | "
                          << "Пройдено: " << std::fixed << std::setprecision(1)
                          << swimmer.distance << " м\n";
            }
            timePassed++;
        }

        // Проверяем, все ли завершили заплыв
        all_finished = true;
        for (const auto& swimmer : swimmers) {
            if (!swimmer.finished) {
                all_finished = false;
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Ждем завершения всех потоков
    for (auto& th : threads) {
        if (th.joinable()) th.join();
    }

    // Выводим финальные результаты
//    system("clear");
    std::cout << "Результаты заплыва:\n";
    // Сортируем по времени прохождения
    std::sort(swimmers.begin(), swimmers.end(), [](const Swimmer& a, const Swimmer& b){
        return a.time_taken < b.time_taken;
    });

    std::cout << std::left << std::setw(15) << "Имя" 
              << "Время (сек)\n";
    for (const auto& swimmer : swimmers) {
        std::cout << std::left << std::setw(15) << swimmer.name 
                  << swimmer.time_taken << "\n";
    }

    return 0;
}