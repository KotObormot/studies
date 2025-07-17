#include <iostream> 
#include <thread> 
#include <mutex> 
#include <condition_variable>

std::condition_variable cv; 
std::mutex m; 
bool data_ready = false;

void worker_thread() { 
    std::cout << "Worker thread: start" << "\n";
    std::unique_lock<std::mutex> lock(m); 
    cv.wait(lock, []{ 
        return data_ready; 
    }); // Ожидание пока data_ready == true 
    std::cout << "Worker thread: data is ready!" << std::endl;
}

int main() { 
    std::thread worker(worker_thread);

    { 
        std::lock_guard<std::mutex> lock(m);
        // Имитация обработки данных
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        data_ready = true; 
        std::cout << "Main thread: Data is ready, notifying worker thread." << std::endl;
    }
    cv.notify_one(); // Уведомление одного ожидающего потока
    
    worker.join(); 
    return 0;
}