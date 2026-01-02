/*auto_ptr
не используется потому, что он устарел в C++11, удален в C++17 и имеет неудовлетворительную семантику копирования, которая несовместима с контейнерами STL и приводит к запутыванию из-за установки скопированного auto_ptr в нулевой указатель. На его замену пришел std::unique_ptr, который обеспечивает единоличное владение ресурсом, а не копирование, и корректно работает с контейнерами стандартной библиотеки C++. 
Проблемы auto_ptr

    Устаревшая семантика копирования: auto_ptr был создан до появления семантики перемещения в C++11. Для выполнения операций, которые приводили к копированию (например, передача в функцию или сохранение в контейнер), auto_ptr фактически "перемещал" право собственности на объект, обнуляя исходный указатель.
    Несовместимость с контейнерами STL: Эта странная семантика копирования делала auto_ptr невозможным для использования в контейнерах стандартной библиотеки, таких как vector или list.
    Проблемы с владением: Не было четкого механизма совместного владения, что часто приводило к ошибкам. 

Решение — std::unique_ptr

    Единоличное владение: std::unique_ptr предназначен для единоличного владения динамически выделенным объектом. В отличие от auto_ptr, его нельзя просто так скопировать.
    Поддержка семантики перемещения: unique_ptr корректно работает с семантикой перемещения, позволяя эффективно передавать право собственности на объект.
    Совместимость с STL: unique_ptr можно использовать в контейнерах стандартной библиотеки.
    Лучшая замена: Начиная с C++11, std::unique_ptr стал рекомендуемой заменой std::auto_ptr. */
#include <iostream>
#include <memory>

/*
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
*/

int main() {

    std::auto_ptr<int> ap1(new int(5));     //template<class> class std::auto_ptr’ is deprecated: use 'std::unique_ptr' instead [-Wdeprecated-declarations]
    std::cout << ap1.get() << "\t" << *ap1 << "\t" << &ap1 << "\n";
    
    std::auto_ptr<int> ap2(ap1);
//    std::cout << ap1.get() << "\t" << *ap1 << "\t" << &ap1 << "\n";
    std::cout << ap2.get() << "\t" << *ap2 << "\t" << &ap2 << "\n";

    return 0;
}