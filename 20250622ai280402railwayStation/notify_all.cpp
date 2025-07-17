#include <iostream> 
#include <thread> 
#include <mutex> 
#include <condition_variable>

std::mutex mtx; 
std::condition_variable cv; 
bool data_ready = false; 
int result;

void worker_thread() { 
    std::unique_lock<std::mutex> lock(mtx); 
    cv.wait(lock, [] { 
        return data_ready; 
    }); // Ждать, пока data_ready станет true

    std::cout << "Worker thread: Result is " << result << std::endl;
}

void producer_thread() { 
    {
        std::lock_guard<std::mutex> lock(mtx);
        // Подготовка данных
        result = 42; 
        data_ready = true;
    }
    cv.notify_all(); // Пробудить все ожидающие потоки
}

int main() { 
    std::thread worker(worker_thread); 
    std::thread producer(producer_thread);

    producer.join(); 
    worker.join();

    return 0;
}
