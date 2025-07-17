#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <thread>   // нить

void wait_for_call(int time, std::string name) {
    std::this_thread::sleep_for(std::chrono::seconds(time));  // интервал ожидания time сек
    std::cout << "Id: " << name << ": " << std::this_thread::get_id() << " # " << std::this_thread::get_id << "\n";
    std::cout << "RING (" << name << ")\n";
    std::cout << time << " seconds passed. Answering " << name << "'s call." << "\n";
}

int main() {
    std::cout << "Hello!\n";
    int time;
    std::cout << "Enter time--> ";
    std::cin >> time;
    std::string name;
    std::cout << "Enter name--> ";
    std::cin >> name;
    std::cout << "Id: " << std::this_thread::get_id() << " # " << std::this_thread::get_id << "\n";
    std::thread call(wait_for_call, time, name);
    std::thread callSkillbox(wait_for_call, 4, "Skillbox");

    call.detach();      // отсоединить
    callSkillbox.detach();

    std::this_thread::sleep_for(std::chrono::seconds(5));   // интервал ожидания 5 сек
    std::cout << "RING (Friend)" << "\n";
    std::cout << "5 seconds passed. Answering a friend's call.." << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(10));
    //if(call.joinable()) call.join();    
    //if(call.joinable()) callSkillbox.join();
}