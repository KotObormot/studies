#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#define DEBUG true

struct Character {
    std::string name;
    //std::string s_name;
    //std::string date;
    int health = 0;
    int armor = 0;
    //double salary {0};
};

void save_character(std::ofstream& file, Character& person) {
    int len = person.name.length();
    file.write((char*)&len, sizeof(len));
    file.write(person.name.c_str(), len);
    file.write((char*)&person.health, sizeof(person.health));
    file.write((char*)&person.armor, sizeof(person.armor));
}

void load_character(std::ifstream& file, Character& person) {
    int len;
    file.read((char*)&len, sizeof(len));
    //std::cout << "? " << &len << "! " << "len = " << len << " " << sizeof(len) << "\n";
    person.name.resize(len);
    file.read((char*)person.name.c_str(), len);
    //int s_name_len;
    //file.read((char*)&s_name_len, sizeof(s_name_len));
    //person.s_name.resize(s_name_len);
    //file.read((char*)person.s_name.c_str(), s_name_len);
    //int d_len;
    //file.read((char*)&d_len, sizeof(d_len));
    //person.date.resize(d_len);
    //file.read((char*)person.date.c_str(), d_len);
    file.read((char*)&person.health, sizeof(person.health));
    file.read((char*)&person.armor, sizeof(person.armor));
    //file.read((char*)&person.salary, sizeof(person.salary));
}

void take_damage(Character* person, int damage) {
//    std::cout << person->name << " took damage: -" << damage << std::endl;
    person->armor -= damage;
    if(person->armor < 0) {
        person->health += person->armor;
        person->armor = 0;
    }
}

int main() {
    std::srand(std::time(nullptr));

    //Character people[10];
    std::vector<Character> people {};
    std::string name {};
    //std::string s_name {};
    //std::string date {};
    int health {0};
    int armor {0};
    //double salary {0};

    /*for(int i = 0; i < std::size(people); ++i) {
        people[i].name = "Character #" + std::to_string(i + std::rand() % 13);
        people[i].health = (std::rand() % 100) + 100;
        people[i].armor = (std::rand() % 40) + 10;
    }*/
    int vecNumber = 0;    
    while(vecNumber < 10) {
        name = "Character #" + std::to_string(vecNumber + std::rand() % 13);
        health = (std::rand() % 100) + 100;
        armor = (std::rand() % 40) + 10;
        people.push_back({name, health, armor});
        ++vecNumber;
    }
    #if DEBUG
        std::cout << "vector of structures is written\n";
        for(int i = 0; i < std::size(people); ++i) {
            std::cout << people[i].name << "\t" 
                << people[i].health << "\t" 
                << people[i].armor << "\n";
        }
    #endif

    people[0].name = "Sebile";
    std::ofstream file("./data/save.bin", std::ios::binary);
    for(int i = 0; i < std::size(people); ++i) {
        save_character(file, people[i]);
    }
    file.close();

    std::ifstream file_in("./data/save.bin", std::ios::binary);
    //file.read((char*)&people, sizeof(people));
    for(int i = 0; i < std::size(people); ++i) {
        load_character(file_in, people[i]);
//        people.push_back({name, s_name, date, health, armor, salary});
    }
    file_in.close();
    std::cout << sizeof(people) << " байт, " << std::size(people) << " штук " << "\n";

    for(int i = 0; i < std::size(people); ++i) {
  //      std::cout << people[i].name << ": " << "Health = " << people[i].health 
  //              << ", Armor = " << people[i].armor << "\n";
        std::cout << people[i].name << "\t" 
                << people[i].health << "\t" 
                << people[i].armor << "\n";
    }
    return 0;
}
