#include <iostream>

class Gun {
  public:
    virtual void shoot() {
        std::cout << "Bang! " << "\n";
    }
};

class SubmashinGun : public Gun {
  public:
    void shoot() override {
        std::cout << "Bang! Bang! Bang!" << "\n";
    }
};

class Bazooka : public Gun {
  public:
    void shoot() override {
        std::cout << "BADABUM!" << "\n";
    }
};

class Player {
  public:
    void shoot(Gun* gun) {
        gun->shoot();
    }
};

int main() {
    std::cout << "Hello\n";
    
    Player player;
    
    Gun* ptr = new SubmashinGun;
//    ptr->shoot();
    player.shoot(ptr);

    ptr = new Gun;
//    ptr->shoot();
    player.shoot(ptr);

    ptr = new Bazooka;
    player.shoot(ptr);

    delete ptr;


}