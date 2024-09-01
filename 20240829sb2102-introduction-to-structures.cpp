#include <iostream>
#include <cstdlib>
#include <string>


struct Character {
    char* name = "Unknown"; // ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]gc
    int health = 0;
    int armor = 0;
};

void take_damage(Character* person, int damage) {
    std::cout << person->name << " took damage: -" << damage << std::endl;
    person->armor -= damage;
    if(person->armor < 0) {
        person->health += person->armor;
        person->armor = 0;
    }
}

int main() {
    Character person = {
        "Tom",
        .health = 100,
        /*.armor = 20*/ //вместо инициализации в перечислении применяем отдеьную 
    };
    person.armor = 20;
    take_damage(&person, 30);
    std::cout << person.name << ": " << "Health = " << person.health << ", Armor = "
                << person.armor << "\n";
}