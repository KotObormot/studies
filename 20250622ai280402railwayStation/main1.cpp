#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <chrono>

using namespace std;

// Глобальные объекты для синхронизации
mutex mtx; // мьютекс для защиты общего состояния
condition_variable cv; // условная переменная для ожидания освобождения перрона
bool perron_free = true; // флаг, указывающий свободен ли перрон

// Функция для симуляции работы поезда
void train(const string& name, int arrival_time) {
    // Симуляция времени прибытия
    this_thread::sleep_for(chrono::seconds(arrival_time));
    {
        lock_guard<mutex> lock(mtx);
        cout << "Поезд " << name << " прибыл на вокзал." << endl;
    }

    // Ожидание освобождения перрона
    unique_lock<mutex> lock(mtx);
    while (!perron_free) {
        cout << "Поезд " << name << " ожидает освобождения перрона." << endl;
        cv.wait(lock);
    }
    // Захват перрона
    perron_free = false;
    cout << "Поезд " << name << " занимает перрон." << endl;
}

int main() {
    // Ввод времени пути для каждого поезда
    int t1, t2, t3;
    cout << "Введите время пути первого поезда (в секундах): ";
    cin >> t1;
    cout << "Введите время пути второго поезда (в секундах): ";
    cin >> t2;
    cout << "Введите время пути третьего поезда (в секундах): ";
    cin >> t3;

    // Создаем потоки для поездов
    thread train1(train, "A", t1);
    thread train2(train, "B", t2);
    thread train3(train, "C", t3);

    // Основной поток — управление отправлением поездов
    int trains_remaining = 3;

    while (trains_remaining > 0) {
        string command;
        cout << "\nВведите команду 'depart' для отправки следующего поезда: ";
        cin >> command;

        if (command == "depart") {
            unique_lock<mutex> lock(mtx);
            if (!perron_free) {
                cout << "Перрон занят. Ждите освобождения." << endl;
                continue; // ждем следующей команды
            }
            if (train1.joinable() && train1.get_id() != thread::id()) {
                // Отправляем поезд, если он еще не был отправлен
                perron_free = true; // Освободить перрон после отбытия
                cout << "Поезд A отправляется." << endl;
                train1.detach(); // Отделяем поток (или можно использовать другой механизм)
                trains_remaining--;
            } else if (train2.joinable() && train2.get_id() != thread::id()) {
                perron_free = true;
                cout << "Поезд B отправляется." << endl;
                train2.detach();
                trains_remaining--;
            } else if (train3.joinable() && train3.get_id() != thread::id()) {
                perron_free = true;
                cout << "Поезд C отправляется." << endl;
                train3.detach();
                trains_remaining--;
            } else {
                cout << "Все поезда уже были отправлены или ожидают команду." << endl;
            }
            cv.notify_all(); // уведомляем ожидающих поездов
        } else {
            cout << "Неверная команда. Попробуйте снова." << endl;
        }
    }

    // Ожидаем завершения потоков поездов
    if (train1.joinable()) train1.join();
    if (train2.joinable()) train2.join();
    if (train3.joinable()) train3.join();

    cout << "\nВсе поезда отправлены. Работа вокзала завершена." << endl;

    return 0;
}