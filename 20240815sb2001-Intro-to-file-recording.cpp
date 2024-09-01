#include <fstream>

int main() {
    std::ofstream file("../studies/data/text2001.txt", std::ios::binary);
    file << "Thank god it's friday / T.G.I.F.";

    std::ofstream file1;
    file1.open("./data/text2001-2.txt", std::ios::app);
    file1 << "\nMay the fourth be with you.\n";

    file.close();
    file1.close();
}
