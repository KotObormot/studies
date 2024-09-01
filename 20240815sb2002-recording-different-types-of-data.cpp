#include <fstream>

int main() {
    std::ofstream file("./data/text2002.txt");
    file.setf(std::ios::showpos); // для знака числа
    file.setf(std::ios::showpoint); // для разделительной точки
    file.setf(std::ios::fixed); 
    file.precision(1); // количество значащих цифр после запятой
    file.setf(std::ios::boolalpha); // для булевых переменных
    double temp {-21};
    bool light {true};
    file << temp << " " << light << "\n";

    double temps[] {-18.5, -9, 0, 5.3, 10};
    // char* cond[] как в лекции не заработал
    std::string cond[] {"sunny", "cloudy", "windy", "snowy", "stormy"};

    for(int i = 0; i < 5; ++i) {
        file.width(5);
        file << temps[i];
        file.width(10);
        file << cond[i] << "\n";
    }

    file.close();
}
