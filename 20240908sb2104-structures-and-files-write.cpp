#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
//#include <cstring>
#include <ctime>
#include <vector>

struct Character {
    std::string name {"Unknown"};
    std::string s_name {"Unknown"};
    std::string date {""};
    int health = 0;
    int armor = 0;
    double salary {0};
};

void save_character(std::ofstream& file, Character& person) {
    int len = person.name.length();
    //std::cout << "len=" << len << ", &len=" << &len;
    file.write((char*)&len, sizeof(len));
    //std::cout << ", (char*)&len=" << (char*)&len << ", sizeof(len)=" << sizeof(len);
    file.write(person.name.c_str(), len);
    //std::cout << ", ..name.c_str()=" << person.name.c_str();
    int s_name_len = person.s_name.length();
    file.write((char*)&s_name_len, sizeof(s_name_len));
    file.write(person.s_name.c_str(), s_name_len);
    int d_len = person.date.length();
    file.write((char*)&d_len, sizeof(d_len));
    file.write((char*)person.date.c_str(), d_len);
    file.write((char*)&person.health, sizeof(person.health));
    //std::cout << ", (char*)&..health="  << (char*)&person.health << ":" << sizeof(person.health) << "\n";
    file.write((char*)&person.armor, sizeof(person.armor));
    file.write((char*)&person.salary, sizeof(person.salary));
}

void load_character(std::ifstream& file, Character& person) {
    int len;
    file.read((char*)&len, sizeof(len));
    std::cout << "? " << &len << "! " << "len = " << len << " " << sizeof(len) << "\n";
    person.name.resize(len);
    file.read((char*)person.name.c_str(), len);
    file.read((char*)&person.health, sizeof(person.health));
    file.read((char*)&person.armor, sizeof(person.armor));
}

void take_damage(Character* person, int damage) {
    std::cout << person->name << " took damage: -" << damage;
    person->armor -= damage;
    if(person->armor < 0) {
        person->health += person->armor;
        person->armor = 0;
    }
    std::cout << ", ..health = " << person->health << "\n";
}

int main() {
    std::srand(std::time(nullptr));

//    Character people[3];
    std::vector<Character> people {};
    std::string name {"Unknown1"};
    std::string s_name {"Unknown2"};
    std::string date {"01.01.1901"};
    int health {0};
    int armor {0};
    double salary {0};

    //std::cout << sizeof(people) << " байт, " << std::size(people) << " штук " << "\n";
    int i = 0; 
    while(i < 2) {
    //for(int i = 0; i < std::size(people); ++i) {
        //people[i].name = "Ch-#" + std::to_string(i);
        std::cout << "Name #" << i << "--> ";
        std::cin >> name;
        //std::cin >> people[i].name;
        std::cout << "Surname #" << i << "--> ";
        std::cin >> s_name;
        //std::cin >> people[i].s_name;
        std::cout << "Date #" << i << "--> ";
        std::cin >> date;
        //std::cin >> people[i].date;
        health = (std::rand() % 100) + 100;
        //people[i].health = (std::rand() % 100) + 100;
        //std::cout << "Health #" << i << "--> ";
        //std::cin >> people[i].health;
        armor = (std::rand() % 40) + 10;
        //people[i].armor = (std::rand() % 40) + 10;
        std::cout << "Salary #" << i << "--> ";
        std::cin >> salary;
        //std::cin >> people[i].salary;
        people.push_back({name, s_name, date,health, armor, salary});
        ++i;
    }
    std::cout << sizeof(people) << " bytes, " << std::size(people) << " pcs.\n";
    //for(int i = 0; i < std::size(people); ++i) {
    //    take_damage(people + i, 30);        
    //}

    //people[0].name = "Sebil";

    std::ofstream file("./data/save.bin", std::ios::binary | std::ios::app);
    //for(int i = 0; i < std::size(people); ++i) {
      //  save_character(file, people[i]);
    //}
    file.write((char*)&people, sizeof(people));
    file.close();
/*len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Sebil, (char*)&..health=�:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#1, (char*)&..health={:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#2, (char*)&..health=�:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#3, (char*)&..health=�:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#4, (char*)&..health=b:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#5, (char*)&..health=w:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#6, (char*)&..health=�:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#7, (char*)&..health=�:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#8, (char*)&..health=�:4
len=5, &len=0x7ffe6f974ef4, (char*)&len=, sizeof(len)=4, ..name.c_str()=Ch-#9, (char*)&..health=�:4*/

}
