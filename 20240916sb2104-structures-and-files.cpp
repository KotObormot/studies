#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

struct Character {
    std::string name = "unknown";
    int health = 0;
    int armor = 0;
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
    person.name.resize(len);
    file.read((char*)person.name.c_str(), len);
    file.read((char*)&person.health, sizeof(person.health));
    file.read((char*)&person.armor, sizeof(person.armor));
}

void take_damage(Character* person, int damage) {
    std::cout << person->name << " took damage: -" << damage;
    person->armor -= damage;
   if(person->armor < 0) {
        person->health += person->armor;
        person->armor = 0;
    }
    std::cout << ", ..health = " << person->health << "\n";
}


int main() {
    std::srand(std::time(nullptr));
    Character people[10];
    for(int i = 0; i < std::size(people); ++i) {
        people[i].name = "Character #" + std::to_string((i * (std::rand() % 5) * 3 + (std::rand() % 30) + 30 ));
        people[i].health = (std::rand() % 100) + 100;
        people[i].armor = (std::rand() % 40) + 10;
    }
    people[0].name = "Sebile";
    std::ofstream file("./data/save.bin", std::ios::binary);
    for(int i = 0; i < std::size(people); ++i) {
        save_character(file, people[i]);
    }
    file.close();

    std::ifstream file_in("./data/save.bin", std::ios::binary);
    for(int i = 0; i < std::size(people); ++i) {
        load_character(file_in, people[i]);
    }
    file.close();

    for(int i = 0; i < std::size(people); ++i) {
        std::cout << people[i].name << " : " 
                << people[i].health << " - "
                << people[i].armor << "\n";
    }
    return 0;
}