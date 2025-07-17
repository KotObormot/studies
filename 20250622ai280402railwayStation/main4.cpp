#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;
bool perron_free = true;

void progressBar() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << "= ";
    }
}

struct Train {
    string name;
    int travel_time;
    thread th;
    bool arrived = false; // прибыл ли поезд
    bool departed = false; // отправлен ли поезд
};

void train_func(Train& train) {
    // Симуляция прибытия
    this_thread::sleep_for(chrono::seconds(train.travel_time));
    {
        lock_guard<mutex> lock(mtx);
        cout << "Поезд " << train.name << " прибыл на вокзал." << endl;
        train.arrived = true;
    }
    // Ожидание освобождения перрона
    unique_lock<mutex> lock(mtx);
    while (!perron_free) {
        cout << "Поезд " << train.name << " ожидает освобождения перрона." << endl;
        cv.wait(lock);
    }
    // Захват перрона
    perron_free = false;
    cout << "Поезд " << train.name << " занимает перрон." << endl;
}

int main() {
    int t1, t2, t3;
    cout << "Введите время пути первого поезда (в секундах): ";
    cin >> t1;
    cout << "Введите время пути второго поезда (в секундах): ";
    cin >> t2;
    cout << "Введите время пути третьего поезда (в секундах): ";
    cin >> t3;

    Train trains[3] = {
        {"A", t1},
        {"B", t2},
        {"C", t3}
    };

    // Запускаем потоки для каждого поезда
    for (int i = 0; i < 3; ++i) {
        trains[i].th = thread(train_func, ref(trains[i]));
    }

    //std::thread prgrssBr(progressBar);
    //prgrssBr.detach();
    int remaining_trains = 3;

    while (remaining_trains > 0) {
        string cmd;
        cout << "\nВведите команду 'depart' для отправки следующего поезда: ";
        cin >> cmd;

        if (cmd == "depart") {
            unique_lock<mutex> lock(mtx);
            // Проверяем есть ли поезд на перроне
            bool train_on_perron = false;
            for (int i = 0; i < 3; ++i) {
                if (trains[i].arrived && !trains[i].departed && !trains[i].th.joinable()) {
                    // Поезд уже отправлен или поток завершен
                    continue;
                }
                if (trains[i].arrived && !trains[i].departed) {
                    train_on_perron = true;
                    // Отправляем этот поезд
                    cout << "Поезд " << trains[i].name << " отправляется." << endl;
                    // Освобождаем перрон
                    perron_free = true;
                    cv.notify_all();
                    lock.unlock();

                    // Имитация времени отбытия
//                    this_thread::sleep_for(chrono::seconds(2));

                    // Завершаем поток поезда после отправки
                    trains[i].departed = true;

                    // Ждем завершения потока
                    if (trains[i].th.joinable()) {
                        trains[i].th.join();
                    }

                    remaining_trains--;
                    break; // только один поезд за раз
                }
            }
            if (!train_on_perron) {
                cout << "Нет поезда на перроне для отправки или все уже отправлены." << endl;
            }
        } else {
            cout << "Неверная команда. Попробуйте снова." << endl;
        }
    }
    cout << "\nВсе поезда отправлены. Работа вокзала завершена." << endl;

    return 0;
}