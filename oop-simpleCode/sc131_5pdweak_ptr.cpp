// https://www.youtube.com/watch?v=nZNcRRXeKTk&t=430s

#include <iostream>
#include <memory>


int main() {
    std::weak_ptr<int> wp;
    {
        auto sp(std::make_shared<int>(5));
        wp = sp;

        std::cout << "Expired1: " << std::boolalpha << wp.expired() << "\n";   // Не просрочен

        // Доступ к объекту
        // 1-й способ
        auto sp1(wp.lock());
        std::cout << sp1 << "\t" << sp1.get() << "\t" << *sp1 << "\n";
        
        // 2-й способ
        auto sp2 {std::shared_ptr<int>(wp)};                     // wrong auto sp2(std::shared_ptr<int>(wp)); 
//        std::shared_ptr<int> sp2 = std::make_shared<int>(wp);     // also wrong
        std::cout << sp2 << "\t" << sp2.get() << "\t" << *sp2 << "\n";
    } 

    auto newShared(wp.lock());                              // 1-м способом
    std::cout << "newShared: " << newShared.get() << "\n";                          // Просрочен
    
    std::cout << "Expired2: " << wp.expired() << "\n";                          // Просрочен

    try 
    {
        auto newShared2 = std::shared_ptr<int>(wp);         // 2-м способом
    }
    catch(std::bad_weak_ptr &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}