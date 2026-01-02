#include <iostream>

class IBicycle {            // интерфейс
  public:
    void virtual ewistTheWeel() = 0;
    void virtual ride() = 0;
};

class SimleBicycle : public IBicycle {      // реализуем интерфейс
  public:
    void ewistTheWeel() override {
        std::cout << "wistTheWeel()\tSimleBicycle\n";
    }

    void ride() override {
        std::cout << "ride()\tSimleBicycle\n";
    }

};

class SportBicycle : public IBicycle {      // реализуем интерфейс
  public:
    void ewistTheWeel() override {
        std::cout << "wistTheWeel()\tSportBicycle\n";
    }

    void ride() override {
        std::cout << "ride()\tSportBicycle\n";
    }

};

class Human {
  public:
    void rideOn(IBicycle& bicycle) {
        std::cout << "Крутим руль" << "\n";
        bicycle.ewistTheWeel();
        std::cout << "\n" << "Поехали" << "\n";
        bicycle.ride();
    }
};

int main() {
    std::cout << "Hello\n";
    SimleBicycle sb;
    SportBicycle spB;
    Human human;
    human.rideOn(sb);
    std::cout << "\n";
    human.rideOn(spB); 
}