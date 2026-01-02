#include <iostream>

#define WITH_SMARTPTR true

#if WITH_SMARTPTR
template<typename T>

class SmartPointer {
  public:
    SmartPointer(T* ptr) {
        this->ptr = ptr;
        std::cout << "Created SmartPointer " << this // on the stack == stack allocation
                  << "\t" << this->ptr               // in the heap == on the heap 
                  << "\t" << *this->ptr
                  << "\t" << &this->ptr
                  << "\t" << ptr                    // in the heap == on the heap 
                  << "\t" << *ptr
                  << "\t" << &ptr
                  << "\n";
    }

    ~SmartPointer() {
        std::cout << "Deleted SmartPointer " << this << "\t" << this->ptr << "\t" << ptr << "\n";
        delete ptr;
    }

    T& operator*() {
        return *ptr;
    }

  private:
    T* ptr;
};
#endif

int main() {
#if WITH_SMARTPTR
    SmartPointer<int> pointer = new int(5);
    std::cout << *pointer << "\t" << &pointer << "\n";

    *pointer = 20;
    std::cout << *pointer << "\t" << &pointer << "\n";

#else
    int* ptr = new int/*(5)*/;

    std::cout << ptr << "\t" << *ptr << "\t" << &ptr << "\t" /*<< &*ptr*/ << "\n";
    int* ptr2 = ptr;
    std::cout << ptr2 << "\t" << *ptr2 << "\t" << &ptr2 << "\t" /*<< &*ptr2*/ << "\n";
//    ptr = nullptr;
    delete ptr;
    ptr = nullptr;
 //   std::cout << ptr << "\t" << *ptr << "\t" << &ptr << "\t" /*<< &*ptr*/ << "\n";

    std::cout << ptr2 << "\t" << *ptr2 << "\t" << &ptr2 << "\t" /*<< &*ptr2*/ << "\n";

    ptr2 = nullptr;
//    std::cout << ptr2 << "\t" << *ptr2 << "\t" << &ptr2 << "\t" /*<< &*ptr2*/ << "\n";

#endif
    return 0;
}