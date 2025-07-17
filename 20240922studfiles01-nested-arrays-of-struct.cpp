// https://studfile.net/preview/5622264/page:2/#6
#include <iostream>

struct Time {
    int hour, min, sec;
};
struct Date {
    int day, month, year; 
};

struct Matr {
    int a[2][3];
    float b[3];
    char fio[20];
};

struct Person {
    char fam[20]; 
    Date birthday; // вложенная структура Date
    long telNumber;
};

struct DateTime { 
    Date today;
    Time now;
};

int main() {
    DateTime dt;
    dt.today.day = 2;
    dt.today.month = 4;
    dt.today.year = 2001;
    dt.now.hour = 10;
    dt.now.min = 26;
    dt.now.sec = 33;
    std::cout << dt.today.day << "." << dt.today.month << "." << dt.today.year << " "
              << dt.now.hour << ":" << dt.now.min << ":" << dt.now.sec <<  "\n";
    /******************************************************************************* */
    Date list[10];
    const int n = 100;
    Person p1[n];
    Matr matr[n];
    std::cin >> list[1].day;
    std::cout << list[1].day << "\n";
    //std::cout << p1[0].birthday.day << "\n";
   // matr[0].a[0][1] = 25;
    //std::cout << matr[0].a[0][1] << "\n";
}