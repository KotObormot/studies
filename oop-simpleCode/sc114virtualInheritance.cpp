#include <iostream>
//#include <string>

class Character {
  public:
    Character() {
        std::cout << "Конструктор Character" << "\n";
    }
    int hp;
};

class Orc : public virtual Character {                // класс Character, т.о. делается виртуальным
  public:
    Orc() {
        std::cout << "Конструктор Orc" << "\n";
    }
};

class Warrior : public virtual Character {
  public:
    Warrior() {
        std::cout << "Конструктор Warrior" << "\n";
    }
};

class OrcWarrior: public Orc, public Warrior {
  public:
    OrcWarrior() {
        std::cout << "Конструктор OrcWarrior" << "\n";
    }
};

int main() {
    std::cout << "Hello\n";
    OrcWarrior ow;
}

