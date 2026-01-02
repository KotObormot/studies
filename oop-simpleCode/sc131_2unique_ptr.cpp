#include <iostream>
#include <memory>

int main()
{

    std::unique_ptr<int> up1(new int(5));
    std::cout << up1.get() << "\t" << *up1 << "\t" << &up1 << "\n";

    //    std::unique_ptr<int> up2(up1);      //use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’gcc
    std::unique_ptr<int> up2;
    up2 = std::move(up1); // or up2.swap(up1);
                          //    up2.swap(up1);
    std::cout << up1.get() /*<< "\t" << *up1 << "\t" << &up1*/ << "\n";
    std::cout << up2.get() << "\t" << *up2 << "\t" << &up2 << "\n";

    std::unique_ptr<int> up3(std::make_unique<int>(20));
    std::cout << up3.get() << "\t" << *up3 << "\t" << &up3 << "\n";
    up3.reset();
    std::cout << "!up3 = " << std::boolalpha << !up3 << ": ";
    if(!up3) {
        std::cout << "Memory is free" << "\n";
    } else {
        std::cout << up3.get() << "\t" << *up3 << "\t" << &up3 << "\n";
    }

    /*
Выражение !up4 в данном контексте имеет тип bool и значение false. std::unique_ptr перегружает оператор логического отрицания !. Когда unique_ptr содержит валидный указатель (т.е. не nullptr), оператор ! возвращает false. Если же unique_ptr пустой (т.е. хранит nullptr), то оператор ! возвращает true. В данном случае up4 инициализирован с помощью std::make_unique<int>(30), что означает, что он содержит валидный указатель на выделенную динамическую память, следовательно, !up4 будет равно false.
*/
    std::unique_ptr<int> up4(std::make_unique<int>(30));
    std::cout << up4.get() << "\t" << *up4 << "\t" << &up4 << "\n";
    up4.reset(new int(31));
    std::cout << up4.get() << "\t" << *up4 << "\t" << &up4 << "\n";

    auto up5(std::make_unique<int>(40));
    std::cout << up5.get() << "\t" << *up5 << "\t" << &up5 << "\n";
    int* p5 = up5.release();
    std::cout /*<< std::boolalpha*/ << "!up5=" << !up5 << ": ";
    if(!up5) {
        std::cout << "Memory is free" << "\n";
    } else {
        std::cout << up5.get() << "\t" << *up5 << "\t" << &up5 << "\n";
    }
    
    std::cout /*<< std::boolalpha*/ << "!p5=" << !p5 << ": " << p5 << "\t" << *p5 << "\t" << &p5 << "\n";
    if(p5) {
        delete p5;
        std::cout << p5 << "\t" << *p5 << "\t" << &p5 << "\n";
        p5 = nullptr;
        std::cout << p5 /*<< "\t" << *p5 << "\t" << &p5*/ << "\n";
    }
    
    return 0;
}
/*Методы release() и reset() у unique_ptr в C++ оба позволяют управлять владением указателем, но делают это по-разному. release() отсоединяет указатель от объекта, передавая владение вызывающему, в то время как reset() может как отсоединить указатель, так и переназначить его на другой объект, освобождая предыдущий. 
release():

    Отсоединяет указатель от объекта, которым он владел, "высвобождая" его.
    Возвращает необработанный указатель на объект.
    Вызывающий код теперь отвечает за управление памятью этого объекта (например, удаление).
    unique_ptr больше не владеет объектом и не будет его удалять. 

C++

std::unique_ptr<int> ptr(new int(10));
int* raw_ptr = ptr.release(); // ptr больше не владеет памятью

// Теперь вызывающий код должен удалить raw_ptr
if (raw_ptr) {
    delete raw_ptr;
}

reset():

    Если указатель не пустой, сначала освобождает объект, которым владел unique_ptr.
    Затем, если передан аргумент, переустанавливает указатель на новый объект или nullptr, если аргумент не передан.
    Если аргумент не передан, то unique_ptr становится пустым (владеет nullptr). 

C++

std::unique_ptr<int> ptr(new int(10));
ptr.reset(new int(20)); // Освобождает 10, и теперь владеет 20
ptr.reset(); // Освобождает 20, и ptr становится пустым (nullptr)

Ключевые отличия:

    release() всегда отсоединяет указатель и передает владение, а reset() может как отсоединить, так и переназначить, а также очистить unique_ptr.
    release() возвращает необработанный указатель, а reset() не возвращает ничего.
    reset() более универсален, так как позволяет как освобождать старый объект, так и переустанавливать указатель на новый. 

    Класс unique_ptr | Microsoft Learn
    Класс unique_ptr заменяет значение auto_ptr и может использоваться в качестве элемента контейнеров стандартной библиотеки C++. Исп...
    Microsoft Learn

override (C++/CLI и C++/CX) - Learn Microsoft
override (C++/CLI и C++/CX) Контекстно-зависимое ключевое слово override указывает, что член типа переопределяет член базового кла...
Microsoft Learn
В ответах искусственного интеллекта могут быть ошибки. Подробнее…
*/