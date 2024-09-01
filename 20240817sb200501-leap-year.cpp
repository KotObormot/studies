// https://ru.stackoverflow.com/questions/896871/%D0%92%D0%B8%D1%81%D0%BE%D0%BA%D0%BE%D1%81%D0%BD%D1%8B%D0%B9-%D0%B3%D0%BE%D0%B4-%D0%B1%D0%B5%D0%B7-%D1%83%D1%81%D0%BB%D0%BE%D0%B2%D0%B8%D0%B9-%D0%B8-%D1%86%D0%B8%D0%BA%D0%BB%D0%BE%D0%B2-c

#include <iostream>

int main() {
    /*
        1. Год делится на 400->високосный->конец
        2. Год делится на 100->не високосный->конец
        3. Год делится на 4->високосный->конец
        4. Год не високосный->конец
        5. Всё
    */
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;
    if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
        std::cout << "Leap.\n";
    } else {
        std::cout << "Not leep.\n";
    }
 
    return 0;
}
