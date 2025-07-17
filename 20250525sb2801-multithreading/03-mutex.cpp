#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <thread>   // нить
#include <mutex>    // мьютекс

#define DEBUG_DETACH true

std::vector<std::string> history;   //  история
std::mutex history_access;          // доступ к истории

void wait_for_call(int time, std::string name) {
    std::this_thread::sleep_for(std::chrono::seconds(time));  // интервал ожидания time сек
    std::cout << "Id: " << name << ": " << std::this_thread::get_id() << " # " << std::this_thread::get_id << "\n";
    std::cout << "RING (" << name << ")\n";
    std::cout << time << " seconds passed. Answering " << name << "'s call." << "\n";

    history_access.lock();      // блокировка доступа к истории
    history.push_back(name);    // добавление имени к истории
    history_access.unlock();    // разблокировка доступа к истории
}

int main() {
    std::cout << "Hello!\n";
    std::cout << "Id: main: " << std::this_thread::get_id() << " # " << std::this_thread::get_id << "\n";
    int time;
    std::cout << "Enter time--> ";
    std::cin >> time;
    std::string name;
    std::cout << "Enter name--> ";
    std::cin >> name;
    std::thread call(wait_for_call, time, name);
    std::thread callSkillbox(wait_for_call, 4, "Skillbox");

#if DEBUG_DETACH
    call.detach();      // отсоединить
    callSkillbox.detach();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    if(call.joinable()) call.join();    
    if(call.joinable()) callSkillbox.join();
#else
    call.join(); 
    callSkillbox.join();
#endif

    history_access.lock();
    std::cout << "\n================\nCalls:\n";
    for(auto call : history) {
        std::cout << call << "\n";
    }
    std::cout << "\n";
    history_access.unlock();
}