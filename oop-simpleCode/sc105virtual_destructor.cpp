#include <iostream>
#include <string>

class A {
  public:
    A() {
        std::cout << "Выделена динамическая память, объект класса A " << this << "\n";
    }

    virtual ~A() {
        std::cout << "Освобождена динамическая память, объект класса A " << this << "\n";
    }
};

class B : public A {
  public:
    B() {
        std::cout << "Выделена динамическая память, объект класса B " << this << "\n";
    }

    ~B() override {
        std::cout << "Освобождена динамическая память, объект класса B " << this << "\n";
    }
};

class C : public A {
  public:
    C() {
        std::cout << "Выделена динамическая память, объект класса C " << this << "\n";
    }

    ~C() override {
        std::cout << "Освобождена динамическая память, объект класса C " << this << "\n";
    }
};

class D : public A {
  public:
    D() {
        std::cout << "Выделена динамическая память, объект класса D " << this << "\n";
    }

    ~D() override {
        std::cout << "Освобождена динамическая память, объект класса D"  << this << "\n";
    }
};

int main() {
    std::cout << "Hello\n";

    A* ptrA;
    
    ptrA = new B; 
    std::cout << "\n";
    delete ptrA;

    std::cout << "=================\n";

    ptrA = new C;
    std::cout << "\n";    
    delete ptrA;

    std::cout << "=================\n";

    ptrA = new D;
    std::cout << "\n";    
    delete ptrA;

    
    return 0;
}