#include <iostream>
#include <cstdlib>
#include <string>

struct Character { // Структура Персонаж
 //   char* name =  "unknown"; // имя ISO C++11 does not allow conversion from string literal to 'char *' (clang - Wwritable-strings)  
    std::string name {"unknown"};
    int health {0}; // жизнь
    int armor {0}; // броня
}; // Не забываем поставить ;

void take_damage(Character* person, int damage) { // получить_урон
    std::cout << person->name  << " took damage: -" << damage << "\n";    
    person->armor -= damage;
    if(person->armor < 0) {
        person->health += person->armor;
        person->armor = 0;
    }
}

void take_damage_reference(Character& person, int damage) { // получить_урон
    std::cout << person.name  << " took damage: -" << damage << "\n";    
    person.armor -= damage;
    if(person.armor < 0) {
        person.health += person.armor;
        person.armor = 0;
    }
}

int main() {
//    Character person = {"Tom", 100 };
    Character people[10]; // массив структур из 10 структур
//    person.armor = 20;
    std::cout << sizeof(people) << " байт, " << std::size(people) << " штук "/* << people.std::size()*/ << "\n";
    for(int i = 0; i < std::size(people); ++i) {
        people[i].name = "Character #" + std::to_string(i);
        people[i].health = (std::rand() % 100) + 100;
        people[i].armor = (std::rand() % 40) + 10;
    }
//    Передача указателя(адреса переменной-структуры
    for(int i = 0; i < std::size(people); ++i) {
        take_damage(&people[i], 30);
    }

// То же с адресной арифметикой:
    for(int i = 0; i < std::size(people); ++i) {
        take_damage(people + i, 30);
    }

// То же по ссылке
    for(int i = 0; i < std::size(people); ++i) {
        take_damage_reference(people[i], 30);
    }

    for(int i = 0; i < std::size(people); ++i) {    
        std::cout << "Character #" + std::to_string(i)  << "Health: " << people[i].health << " Armor: " << people[i].armor << "\n";
    }
}
