//бинарный файловый ввод-вывод
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // для exit

inline void eatline() {
    while(std::cin.get() != '\n') {
        continue;
    }
}

struct Planet {
    char name[20]; // название планеты
    double population; // население
    double g;          // ускорение свободного падения
};

const char* file = "./data/planets.dat";

int main () {
    Planet pl;
    std::cout << std::fixed << std::right;
    //Отображение начального содержимого
    std::ifstream fin;
    fin.open(file, std::ios::in | std::ios::binary);
    if(fin.is_open()) {
        std::cout << "Here are the current contents of the "
                    << file << ":\n";
        while(fin.read((char*)&pl, sizeof(pl))) {
            std::cout << std::setw(20) << pl.name << ": "
                    << std::setprecision(0) << std::setw(20) << pl.population
                    << std::setprecision(2) << std::setw(6) << pl.g << "\n";
        }
        fin.close();
    }
    // Добавлниее новых данных
    std::ofstream fout(file, std::ios::out | std::ios::binary | std::ios::app);
    /*if(!fout.is_open()) {
        std::cerr << "Error\n";
        exit(EXIT_FAILURE);
    }*/
    std::cout << "Planet name or a blank line to quit--> ";
    std::cin.get(pl.name, 20);
    while(pl.name[0] != '\0') {
        eatline();
        std::cout << "Population--> ";
        std::cin >> pl.population;
        std::cout << "G--> ";
        std::cin >> pl.g;
        eatline();
        fout.write((char*)&pl, sizeof(pl));
        std::cout << "Planet name or a blank line to quit--> ";
        std::cin.get(pl.name, 20); 
    }
    fout.close();
   // Отображение измененного файла
   //fin.clear(); //необязательно

    fin.open(file, std::ios::in | std::ios::binary);
    if(fin.is_open()) {
        std::cout << "Here are the current contents of the "
                    << file << ":\n";
        while(fin.read((char*)&pl, sizeof(pl))) {
            std::cout << std::setw(20) << pl.name << ": "
                    << std::setprecision(0) << std::setw(20) << pl.population
                    << std::setprecision(2) << std::setw(6) << pl.g << "\n";
        }
    }
}
