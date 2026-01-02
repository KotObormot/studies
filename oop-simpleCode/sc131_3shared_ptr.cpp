#include <iostream>
#include <memory>

int main() {

    std::shared_ptr<int> sp1(new int(5));
    std::cout << sp1.get() << "\t" << *sp1 << "\t" << &sp1 << "\t" << sp1.use_count() << "\n";
    
    std::shared_ptr<int> sp2(sp1);
    std::cout << sp2.get() << "\t" << *sp2 << "\t" << &sp2 << "\t" << sp2.use_count()  << "\n";

    std::shared_ptr<int> sp3(sp2);    
    std::cout << sp3.get() << "\t" << *sp3 << "\t" << &sp3 << "\t" << sp3.use_count()  << "\n";

    sp3.reset();
    sp2.reset();
    sp1.reset();
    std::cout << sp1.use_count() << "\n";
    
    std::weak_ptr<int> wp1(sp1);
    std::cout /*<< wp1.get() << "\t" << *wp1*/ << "\t" << &wp1 << "\t" << wp1.use_count() << "\t" << wp1.expired() << "\n";

    std::weak_ptr<int> wp2(wp1);
    std::cout /*<< wp1.get() << "\t" << *wp1*/ << "\t" << &wp2 << "\t" << wp2.use_count() << "\n";

    std::weak_ptr<int> wp3(wp2);
    std::cout /*<< wp1.get() << "\t" << *wp1*/ << "\t" << &wp3 << "\t" << wp3.use_count() << "\n";

    wp3.reset();
    std::cout << wp1.use_count();

    return 0;
}