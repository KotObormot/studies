// Вызов конструктора базового класса (когда их несколько) из конструктора класса-наследника. Наследование. ООП C++ #102 

#include <iostream>
#include <string>

class A {
  public:
    A() {
        std::cout << "Пустое сообщение" << "\n";
    }

    A(std::string msg) {
        this->msg = msg;
    }

    void printMsg() {
        std::cout << msg << "\n";
    }

  private:
    std::string msg;
};

class B : public A {
  public:
    B() {}                                  // Дефолтный или так 
//    B() : A("Message") {}                 // ... или так

    B(std::string msg) : A(msg) {}          
};

int main() {
    std::cout << "Hello\n";
    
    B value1;
    value1.printMsg();
    B value2("New message");
    value2.printMsg();
    std::cout << "\n";
}