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

    // Assignment operator
    MyClass& operator = (const MyClass& other) {
        std::cout << "Assignment operator MyClass(data)\t" << this << "\n";
        if(this == &other) {
            return *this;
        }
        this->size1 = other.size1;
        if(this->data != nullptr) {
            delete[] this->data;
        }
        this->data = new int[other.size1];
        for(int i(0); i < other.size1; ++i) {
            this->data[i] = other.data[i];
        }

        return *this;
    }

    /*void print() {
        for(int i(0); i < data.)
    }*/

  private:
    int size1;
};

int main() {
    MyClass a(10);

    MyClass b(2);

    a = b;

    return 0;
}