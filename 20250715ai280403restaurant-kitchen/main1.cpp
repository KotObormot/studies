#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

struct Meal {
    int id;
    bool is_ready;
};

class Kitchen {
public:
    Kitchen() : order_count(0), completed_orders(0), stop(false) {}

    void start() {
        // Запуск потоков
        order_thread = std::thread(&Kitchen::generate_orders, this);
        courier_thread = std::thread(&Kitchen::courier_service, this);
        worker_thread = std::thread(&Kitchen::work, this);
    }

    void join() {
        order_thread.join();
        courier_thread.join();
        worker_thread.join();
    }

private:
    std::mutex mtx;
    std::condition_variable cv_order;     // Для уведомления о новом заказе
    std::condition_variable cv_ready;     // Для уведомления о готовности блюда
    std::queue<Meal> order_queue;           // Очередь ожидающих заказов
    std::vector<Meal> ready_meals;          // Готовые блюда для курьера

    int order_count;                        // Общее количество заказов (для генерации ID)
    int completed_orders;                   // Количество выполненных заказов
    bool stop;                              // Флаг завершения работы

    std::thread order_thread;
    std::thread courier_thread;
    std::thread worker_thread;

    void generate_orders() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(7));
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (completed_orders >= 10) {
                    stop = true;
                    cv_order.notify_all();
                    break;
                }
                order_count++;
                Meal new_meal{order_count, false};
                order_queue.push(new_meal);
                std::cout << "Поступил заказ #" << new_meal.id << "\n";
            }
            cv_order.notify_one();
        }
        std::cout << "Все заказы выполнены. Завершение работы.\n";
    }

    void work() {
        while (true) {
            Meal current_meal;
            {
                std::unique_lock<std::mutex> lock(mtx);
                // Ждем заказа или сигнала о завершении
                cv_order.wait(lock, [this] { return !order_queue.empty() || stop; });
                if (stop && order_queue.empty()) break;

                current_meal = order_queue.front();

                // Если кухня занята, ждем освобождения
                if (current_meal.is_ready) {
                    // Блюдо уже готово, его можно забрать курьеру
                    continue;
                } else {
                    // Забираем заказ для приготовления
                    order_queue.pop();
                    std::cout << "Кухня начала готовить заказ #" << current_meal.id << "\n";
                }
            }

            // Готовим блюдо 12 секунд
            std::this_thread::sleep_for(std::chrono::seconds(12));

            {
                std::lock_guard<std::mutex> lock(mtx);
                current_meal.is_ready = true;
                ready_meals.push_back(current_meal);
                std::cout << "Заказ #" << current_meal.id << " готов.\n";
            }
            cv_ready.notify_one();

            // Проверка на завершение после каждого приготовления
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (completed_orders >= 10) break;
            }
        }
    }

    void courier_service() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            std::vector<Meal> to_deliver;

            {
                std::lock_guard<std::mutex> lock(mtx);
                if (stop && ready_meals.empty()) break;

                // Забираем все готовые блюда
                to_deliver.swap(ready_meals);

                for (const auto& meal : to_deliver) {
                    completed_orders++;
                    std::cout << "Курьер забрал блюдо #" << meal.id << " для доставки.\n";
                    if (completed_orders >= 10) {
                        stop = true;
                        cv_order.notify_all();
                        break;
                    }
                }
            }

            if (stop && ready_meals.empty()) break;
        }
        std::cout << "Курьер завершил работу.\n";
    }
};

int main() {
    Kitchen kitchen;
    kitchen.start();
    kitchen.join();

    return 0;
}