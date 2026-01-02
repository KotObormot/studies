#include <iostream>

class MyClass {
  public:
    int* data;

    MyClass(int size) : size1(size) {
        this->data = new int[size];
        for(int i(0); i < size; ++i) {
            data[i] = i;
        }
        std::cout << "Constructor Myclass(data)\t" << this << "\n";
    }

    ~MyClass() {
        std::cout << "Destructor MyClass\t" << this << "\n";
        delete[] data;
    }

    // Copy Constructor
    MyClass (const MyClass& other) {
        std::cout << "Copy Constructor Myclass(data)\t" << this << "\n";
        this->size1 = other.size1;
        this->data = new int[other.size1];
        for(int i(0); i < other.size1; ++i) {
            this->data[i] = other.data[i];
        }
    }

  private:
    int size1;
};

int main() {
    MyClass a(10);
    MyClass b(a);

    return 0;
}