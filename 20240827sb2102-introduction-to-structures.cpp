//  Structs
//источники: https://radioprog.ru/post/1158 , https://metanit.com/cpp/tutorial/5.8.php
#include <iostream>

struct Person { //По соглашению имена структур начинаются с заглавной буквы, чтобы отличать их от имен переменных.
    unsigned age;
    std::string name;    
};

void console_output(unsigned* ageV, std::string* nameV) {    
    std::cout << "1) Name: " << nameV << "\tAge: " << ageV << std::endl;
    std::cout << "2) Name: " << *nameV << "\tAge: " << *ageV << std::endl;
}

void console_output_pntr(Person* person) {

    std::cout << "3) " << person->age << " " << person->name << "\n";
//    std::cout << "3) " << tom.age << " " << tom.name << "\n"; Member reference type 'person *' is a pointer; did you mean to use '->'? Fix-avaible) (clang typecheck_member_reference_suggestion) 
}

void console_output_struct(Person person) {
    std::cout << "4) " << person.age << " " << person.name << "\n";    
}

void console_output_reference(Person& person) {
    std::cout << "5) " << person.age << " " << person.name << "\n";
}
 
int main() {
    /*---------------------------*/
    Person tom {};
    tom.name = "Tom";
    tom.age = 34;
    console_output(&tom.age, &tom.name);
    console_output_pntr(&tom);
    console_output_struct(tom);
    console_output_reference(tom);
    /*----------------------------*/
    Person jack {43, "Jack"};
    console_output(&jack.age, &jack.name);
    console_output_pntr(&jack);
    console_output_struct(jack);
    std::cout << "\n sizeof = " << sizeof(Person) << "\n";
    console_output_reference(jack);
}
