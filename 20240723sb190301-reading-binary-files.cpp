#include <iostream>
#include <fstream>

int main() {
    char buffer[20];
    std::ifstream bank;
    bank.open("../studies-data/bank.txt", std::ios::binary);
    bank.read(buffer, sizeof(buffer));
    std::cout << "1-й способ вывода в консоль содержимого буфера:\n";
    for(int i = 0; i < sizeof(buffer); ++i) {
        std::cout << buffer[i];
    }
    std::cout << "\n";
    std::cout << "2-й способ вывода в консоль,хотя и с потерей последнего байта:\n";
    buffer[19] = 0;
    std::cout << buffer << "\n";

    
    std::cout << "Считаем данные второй раз:\n";
    bank.read(buffer, sizeof(buffer));
    std::cout << "1-м способом: " << "\n";
    for(int i = 0; i < sizeof(buffer); ++i) {
        std::cout << buffer[i];
    }
    std::cout << "\nИ 2-м способом:\n";    
    buffer[19] = 0;
    std::cout <<  buffer << "\n";
    
    std::cout << "\nСчитаем теперь не в буфер, а в данные int:\n";
    int value;    
    bank.read((char*)&value, sizeof(int));
    std::cout << &value << " " << (char*)&value << " " << sizeof(value) << " " << value << "\n"
            << "получился фарш: символы текстового файла преобразовались в int,\n" 
            << "без всякого парсинга\n\n";
    
    bank.close();
}
