#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <string>
#include <chrono>

struct Meal {
    int id;
    bool is_ready;
};

class Kitchen {
public:
    Kitchen() : stop_accepting(false), next_id(1), total_orders(0), prepared_count(0), delivered_count(0) {}

    void start() {
        input_thread = std::thread(&Kitchen::accept_orders, this);
        worker_thread = std::thread(&Kitchen::prepare_meals, this);
        courier_thread = std::thread(&Kitchen::courier_service, this);
    }

    void join() {
        input_thread.join();
        worker_thread.join();
        courier_thread.join();
    }

private:
    std::mutex mtx;
    std::condition_variable cv_order;     // Для уведомления о новом заказе
    std::condition_variable cv_ready;     // Для уведомления о готовых блюдах
    std::queue<Meal> order_queue;           // Очередь заказов для приготовления
    std::vector<Meal> ready_meals;          // Готовые блюда для курьера

    bool stop_accepting;                    // Флаг прекращения приема заказов
    int next_id;                            // Следующий ID заказа
    int total_orders;                       // Общее число заказов (для подсчета)
    int prepared_count;                     // Количество приготовленных блюд
    int delivered_count;                    // Количество доставленных блюд

    std::thread input_thread;
    std::thread worker_thread;
    std::thread courier_thread;

    void accept_orders() {
        std::string input;
        while (true) {
            std::cout << "Введите заказ или 'STOP' для завершения приема: ";
            std::getline(std::cin, input);
            if (input == "STOP" || input == "stop") {
                {
                    std::lock_guard<std::mutex> lock(mtx);
                    stop_accepting = true;
                }
                cv_order.notify_all();
                break;
            } else {
                // Можно добавить обработку содержимого заказа, сейчас просто создаем заказы с уникальным ID
                Meal new_meal{next_id++, false};
                {
                    std::lock_guard<std::mutex> lock(mtx);
                    order_queue.push(new_meal);
                    total_orders++;
                    std::cout << "Заказ #" << new_meal.id << " добавлен.\n";
                }
                cv_order.notify_one();
            }
        }
        std::cout << "Прием заказов завершен.\n";
    }

    void prepare_meals() {
        while (true) {
            Meal current_meal;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv_order.wait(lock, [this] { return !order_queue.empty() || stop_accepting; });
                if (order_queue.empty() && stop_accepting) {
                    break; // Все заказы приняты и очередь пуста
                }
                if (!order_queue.empty()) {
                    current_meal = order_queue.front();
                    order_queue.pop();
                    std::cout << "Кухня начала готовить заказ #" << current_meal.id << "\n";
                } else {
                    continue;
                }
            }

            // Готовим блюдо 12 секунд
            std::this_thread::sleep_for(std::chrono::seconds(12));

            {
                std::lock_guard<std::mutex> lock(mtx);
                current_meal.is_ready = true;
                ready_meals.push_back(current_meal);
                prepared_count++;
                std::cout << "Заказ #" << current_meal.id << " готов.\n";
            }
            cv_ready.notify_one();

            if (prepared_count >= total_orders && stop_accepting) break;
        }
        // Завершение работы рабочего потока
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop_accepting = true; // Обеспечиваем завершение
        }
        cv_ready.notify_all();
        cv_order.notify_all();
        std::cout << "Рабочий поток завершен.\n";
    }

    void courier_service() {
        while (true) {
            // Ждем 30 секунд между проверками
            std::this_thread::sleep_for(std::chrono::seconds(30));

            bool all_delivered = false;

            {
                std::lock_guard<std::mutex> lock(mtx);
                if (stop_accepting && ready_meals.empty()) {
                    break; // Все блюда забраны и работа завершена
                }

                if (!ready_meals.empty()) {
                    for (const auto& meal : ready_meals) {
                        std::cout << "Курьер забрал блюдо #" << meal.id << " для доставки.\n";
                        delivered_count++;
                    }
                    ready_meals.clear();

                    if (delivered_count >= total_orders && stop_accepting) {
                        all_delivered = true;
                        break;
                    }
                } else if (stop_accepting && ready_meals.empty()) {
                    break;
                }
            }

            if (all_delivered) break;
        }

        // Курьер завершил работу после доставки всех блюд
        std ::cout << "Курьер завершил работу.\n";
    }
};

int main() {
    Kitchen kitchen;
    kitchen.start();
    kitchen.join();

    return 0;
}