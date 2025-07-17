#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <chrono>

struct Meal {
    int id;
    bool is_ready;
};

class Kitchen {
public:
    Kitchen() : total_orders(10), order_id(0), prepared_count(0), stop(false) {}

    void start() {
        order_thread = std::thread(&Kitchen::generate_orders, this);
        worker_thread = std::thread(&Kitchen::work, this);
        courier_thread = std::thread(&Kitchen::courier_service, this);
    }

    void join() {
        order_thread.join();
        worker_thread.join();
        courier_thread.join();
    }

private:
    std::mutex mtx;
    std::condition_variable cv_order;     // Для уведомления о новом заказе
    std::condition_variable cv_ready;     // Для уведомления о готовых блюдах
    std::queue<Meal> order_queue;           // Очередь заказов для приготовления
    std::vector<Meal> ready_meals;          // Готовые блюда для курьера

    int total_orders;       // Максимальное число заказов (10)
    int order_id;           // ID для новых заказов
    int prepared_count;     // Количество приготовленных блюд
    bool stop;              // Флаг завершения

    std::thread order_thread;
    std::thread worker_thread;
    std::thread courier_thread;

    void generate_orders() {
        while (true) {
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (prepared_count >= total_orders) {
                    // Все заказы сделаны
                    break;
                }
                order_id++;
                Meal new_meal{order_id, false};
                order_queue.push(new_meal);
                std::cout << "Поступил заказ #" << new_meal.id << "\n";
            }
            cv_order.notify_one();
            std::this_thread::sleep_for(std::chrono::seconds(7));
        }
        // После завершения генерации заказов — ждем, пока все блюда приготовятся и заберутся
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv_order.notify_all(); // чтобы рабочий мог завершиться
        }
        std::cout << "Все заказы поступили. Ожидаем завершения приготовления.\n";
    }

    void work() {
        while (true) {
            Meal current_meal;
            {
                std::unique_lock<std::mutex> lock(mtx);
                // Ждем заказа или сигнала о завершении
                cv_order.wait(lock, [this] { return !order_queue.empty() || prepared_count >= total_orders; });
                if (order_queue.empty() && prepared_count >= total_orders) {
                    break; // Все заказы сделаны и обработаны
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

            // Если все блюда приготовлены — выходим из цикла
            if (prepared_count >= total_orders) break;
        }
        // Завершение работы рабочего потока
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
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
                if (stop && ready_meals.empty()) {
                    break; // Все блюда забраны и работа завершена
                }

                if (!ready_meals.empty()) {
                    for (const auto& meal : ready_meals) {
                        std::cout << "Курьер забрал блюдо #" << meal.id << " для доставки.\n";
                        ++prepared_count;  // Можно считать доставку как завершение приготовления?
                        // В данном случае лучше считать доставку отдельно или просто завершить после последней забранной порции.
                    }
                    ready_meals.clear();

                    if (prepared_count >= total_orders) {
                        all_delivered = true;
                        break;
                    }
                } else if (stop && ready_meals.empty()) {
                    break;
                }
            }

            if (all_delivered) break;
        }

        // После того как все блюда доставлены — завершаем работу курьера
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }
        cv_ready.notify_all();

        std ::cout << "Курьер завершил работу.\n";
    }
};

int main() {
    Kitchen kitchen;
    kitchen.start();
    kitchen.join();

    return 0;
}