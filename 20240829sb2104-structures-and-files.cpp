#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
//#include <cstring>

struct Character {
    std::string name {"Unknown"};
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
    std::cout << "? " << &len << "! " << "len = " << len << " " << sizeof(len) << "\n";
    person.name.resize(len);
    file.read((char*)person.name.c_str(), len);
    file.read((char*)&person.health, sizeof(person.health));
    file.read((char*)&person.armor, sizeof(person.armor));
}

void take_damage(Character* person, int damage) {
    std::cout << person->name << " took damage: -" << damage << std::endl;
    person->armor -= damage;
    if(person->armor < 0) {
        person->health += person->armor;
        person->armor = 0;
    }
}

int main() {

    Character people[10];
    std::cout << sizeof(people) << " байт, " << std::size(people) << " штук " << "\n";
    //for(int i = 0; i < std::size(people); ++i) {
    //    people[i].name = "Character #" + std::to_string(i);
    //    people[i].health = (std::rand() % 100) + 100;
    //    people[i].armor = (std::rand() % 40) + 10;
    //} 
    //for(int i = 0; i < std::size(people); ++i) {
    //    take_damage(people + i, 30);        
    //}

    //people[0].name = "Sebil";

    //std::ofstream file("./data/save.bin", std::ios::binary);
    //for(int i = 0; i < std::size(people); ++i) {
    //    save_character(file, people[i]);
    //}
    //    file.close();

    std::ifstream file("./data/save.bin", std::ios::binary);
    for(int i = 0; i < std::size(people); ++i) {
        load_character(file, people[i]);
    }
    file.close();

    for(int i = 0; i < std::size(people); ++i) {
        std::cout << people[i].name << ": " << "Health = " << people[i].health 
                << ", Armor = " << people[i].armor << "\n";
    }
}
