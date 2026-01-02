// https://www.youtube.com/watch?v=nZNcRRXeKTk&t=430s

#include <iostream>
#include <memory>

class Cowboy;

class Horse {
  public:
//    std::shared_ptr<Cowboy> owner;
    std::weak_ptr<Cowboy> owner;

    Horse() {
        std::cout << "Horse()\n";
    }
    ~Horse() {
        std::cout << "~Horse()\n";
    }
};

class Cowboy {
  public:
//    std::shared_ptr<Horse> horse;
    std::weak_ptr<Horse> horse;

    Cowboy() {
        std::cout << "Cowboy()\n";
    }
    ~Cowboy() {
        std::cout << "~Cowboy()\n";
    }
};

int main() {
    auto joe(std::make_shared<Cowboy>());
    std::cout << "joe\t" << joe.use_count() << "\n";

    auto lightning(std::make_shared<Horse>());
    std::cout << "lightning\t" << lightning.use_count() << "\n";

    joe->horse = lightning;
    std::cout << "lightning\t" << lightning.use_count() << "\n";
    
    lightning->owner = joe;
    std::cout << "joe\t" << joe.use_count() << "\n";

    return 0;
}