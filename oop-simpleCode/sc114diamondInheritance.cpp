#include <iostream>
#include <string>

class Component {
  public:
    Component(std::string companyName) {
        std::cout << "Конструктор Component" << "\n";
        this->companyName = companyName;
    }

    std::string companyName;
};

class GPU : public Component {
  public:
    GPU(std::string companyName) : Component(companyName) {
        std::cout << "Конструктор GPU" << "\n";
    }
};

class Memory : public Component {
  public:
    Memory(std::string companyName) : Component(companyName) {
        std::cout << "Конструктор Memory" << "\n";
    }
};

class GraphicCard : public GPU, public Memory {
  public:
    GraphicCard(std::string GPUcompanyName, std::string memoryCompanyName) 
            : GPU(GPUcompanyName)
            , Memory(memoryCompanyName) {
        std::cout << "Конструктор GraphicCard" << "\n";
    }
};

int main() {
    std::cout << "Hello\n";
    GraphicCard gc("AMD", "Samsung");
}

