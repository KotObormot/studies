#include <iostream>

#define NEW false

class Weapon {                       // abstract class
  public:
    virtual void shoot() = 0;       // pure virtual function
    void foo() {                    // 
        std::cout << "Foo() " << "\n";
    }
};

class Gun : public Weapon {
  public:
    void shoot() override {
        std::cout << "Bang! " << "\n";
    }
};

class SubmashinGun : public Gun {
  public:
    void shoot() override {
        std::cout << "Bang! Bang! Bang!" << "\n";
    }
};

class Bazooka : public Weapon {
  public:
    void shoot() override {
            std::cout << "BADABUM!" << "\n";
    }
};

class Knife : public Weapon {
  public:
    void shoot() override {
        std::cout << "VJUHH!!" << "\n";
    }
};

class Player {
  public:
    void shootP(Weapon* weapon) {
        weapon->shoot();
    }
};

int main() {
    std::cout << "Hello\n";
    
    Player player;

#if NEW
    Weapon* ptr = new SubmashinGun;
//    ptr->shoot();
    player.shootP(ptr);

    ptr = new Gun;
//    ptr->shoot();
    player.shootP(ptr);

    ptr = new Bazooka;
    player.shootP(ptr);

    ptr = new Knife;
    player.shootP(ptr);

    delete ptr;
#else
    Weapon* ptr/* = SubmashinGun& submashinGun*/;       // ERROR!!!!

    SubmashinGun submashinGun;
    submashinGun.foo();
    ptr = &submashinGun;
    player.shootP(ptr);

    Gun gun;
    ptr = &gun;
    player.shootP(ptr);

    Bazooka bazooka;
    ptr = &bazooka;
    player.shootP(ptr);

    Knife knife;
    ptr = &knife;
    player.shootP(ptr);
#endif

}