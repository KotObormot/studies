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
    Kitchen() : order_count(0), completed_orders(0), total_orders(10), stop(false) {}

    void start() {
        order_thread = std::thread(&Kitchen::generate_orders, this);
        courier_thread = std::thread(&Kitchen::courier_service, this);
        worker_thread = std::thread(&Kitchen::work, this);
    }

    void join() {
        order_thread.join();
        // Ждем завершения работы курьера и обработки блюд
        if (worker_thread.joinable()) worker_thread.join();
        if (courier_thread.joinable()) courier_thread.join();
    }

private:
    std::mutex mtx;
    std::condition_variable cv_order;     // Для уведомления о новом заказе
    std::condition_variable cv_ready;     // Для уведомления о готовых блюдах
    std::condition_variable cv_finished;  // Для ожидания полного завершения
    std::queue<Meal> order_queue;           // Очередь ожидающих заказов
    std::vector<Meal> ready_meals;          // Готовые блюда для курьера

    int order_count;                        // Общее количество заказов (для генерации ID)
    int completed_orders;                   // Количество выполненных заказов
    const int total_orders;                 // Максимальное число заказов
    bool stop;                              // Флаг завершения

    std::thread order_thread;
    std::thread courier_thread;
    std::thread worker_thread;

    void generate_orders() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(7));
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (completed_orders >= total_orders) {
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
        std::cout << "Все заказы поступили. Ожидаем завершения.\n";
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

                // Если блюдо уже в процессе приготовления или готово — пропускаем
                if (current_meal.is_ready) {
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
                if (completed_orders >= total_orders && order_queue.empty()) break;
            }
        }
        // После выхода из цикла — сигнализируем о завершении работы потока
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
            // Спим 30 секунд между проверками
            std::this_thread::sleep_for(std::chrono::seconds(30));

            bool all_delivered = false;

            {
                std::lock_guard<std::mutex> lock(mtx);
                if (stop && ready_meals.empty()) {
                    all_delivered = true;
                    break;
                }

                if (!ready_meals.empty()) {
                    for (const auto& meal : ready_meals) {
                        ++completed_orders;
                        std::cout << "Курьер забрал блюдо #" << meal.id << " для доставки.\n";
                        if (completed_orders >= total_orders) {
                            all_delivered = true;
                            break;
                        }
                    }
                    ready_meals.clear();
                }

                if (all_delivered) break;
            }
        }

        // После того как все блюда доставлены — завершаем работу курьера
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }
        cv_finished.notify_all();

        std ::cout << "Курьер завершил работу.\n";
    }
};

int main() {
    Kitchen kitchen;
    kitchen.start();
    kitchen.join();

    return 0;
}