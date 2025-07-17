#include <iostream>
 
template<typename T> T add(T, T); // прототип функции
 
int main()
{
    std::cout << "int: " << add(4, 5) << std::endl; 
    std::cout << "double: " << add(4.4, 5.5) << std::endl;
    std::cout << "string: " << add(std::string("hel"), std::string("lo")) << std::endl;
}
template<typename T> T add(T a, T b)
{
    return a + b;
}
