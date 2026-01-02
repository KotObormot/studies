#include <iostream>

class MyClass {
  public:
    int data;

    MyClass() {
        std::cout << "Constructor Myclass\t" << this << "\n";
    }

    MyClass(int data) {
        this->data = data;
        std::cout << "Constructor Myclass(data)\t" << this << "\n";
    }

    ~MyClass() {
        std::cout << "Destructor MyClass\t" << this << "\n";
    }

    void print() {
        std::cout << "data: " << this->data << "\t" << this << "\n"; 
    }

    void foo(MyClass value) {
        std::cout << "foo \t" << value.data << "\t" << &value << "\n";
    }

    void fooRefer(MyClass& value) {
        std::cout << "fooRefer \t" << value.data << "\t" << &value << "\n";
    }

    MyClass foo_Return() {
        MyClass temp(2);
        std::cout << "foo_Retur \t" << data << "\t" << this << "\n";

        return temp;
    }
};



int main() {
    MyClass a(1);
    a.print();
    
    a.foo(a);

    a.fooRefer(a);

    std::cout << "foo_RETURN: " << a.foo_Return().data << "\n";

    MyClass b(a);

    return 0;
}