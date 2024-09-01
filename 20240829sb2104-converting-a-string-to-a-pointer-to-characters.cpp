//Преобразование строки в указатель на символы
//Источник https://metanit.com/cpp/tutorial/12.3.php
//
#include <iostream>
#include <string>
#include <cstring>
 
int main()
{
    std::string message {"kgjbpbnpbnptmbpqitjhtpkmbpqttjpttbmpjpktbmpj"};
    const char* message_ptr = message.c_str();  // преобразуем в указатель
    std::cout << message_ptr << std::endl;
    std::cout << message.c_str() << "\n";
//    std::cout << "0) " << std::strlen(message) << "\n"; No viable conversion from 'std::string' (aka 'basic_string<char>') to 'const char *' (clang typecheck_nonviable_condition)                    
    std::cout << "1) " << std::strlen(message_ptr) << "\n";
    std::cout << "2) " << sizeof(message_ptr) << "\n"; //указатель =8 байт
    std::cout << "3) " << sizeof(message) << "\n";
    std::cout << "4) " << std::size(message) << "\n";
    std::cout << "5) " << message.size() << "\n";
//    std::cout << "6) " << std::size(message_ptr) << "\n"; No matching function for call to 'size' (clang ovl_no_viable_function_in_call) 
    std::cout << "6) " << message.length() << "\n";
//    std::cout << "7) " << message_ptr.length() << "\n"; Member reference base type 'const char *' is not a structure or union (clang typecheck_member_reference_struct_union)           
}
