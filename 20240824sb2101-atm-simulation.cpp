#include <fstream>
#include <iostream>
#include <string>

int main() {
    int bills[5] {100, 200, 500, 1000, 5000};
    int money[1000];

    std::cout << "Operation: ";
    std::string operation;
    std::cin >> operation;

    std::ifstream in("./data/money2.bin", std::ios::binary);
    if(in.is_open()) {
        in.read((char*) money, sizeof(money));
        in.close();
    } else {
        for(int i = 0; i < 1000; ++i) {
            money[i] = 0;
        }
    }
    
    if(operation == "+") {
        for(int i = 0; i < 1000; ++i) {
            if(money[i] == 0) {
                money[i] = bills[std::rand() % 5];
            }
        }
    //==============================================
   //     for(int i = 0; i < sizeof(money); ++i) {
     //       std::cout << money[i] << " ";
       // }
      //  std::cout << "\n";
    //***********************************************
        std::ofstream out("./data/money2.bin", std::ios::binary);
        out.write((char*) money, sizeof(money));
        return 0;
    } else if (operation == "-") {
        std::cout << "Amount: ";
        int amount;
        std::cin >> amount;
        if((amount % 100) != 0) {
            std::cerr << "Invalid amount: " << amount << "\n";
            return 1;
        }

        int amount_to_collect {amount};
        for(int i = 4; i >= 0; --i) {
            int bill = bills[i];
            for(int j = 0; j < 1000; ++j) {
                if(money[j] == bill) {
                    if(amount_to_collect >= bill) {
                        money[j] = 0;
                        amount_to_collect -= bill;
                        if(amount_to_collect == 0) {
                            std::cout << "Amount taken: " << amount << "\n";
                            std::ofstream out("./data/money2.bin", std::ios::binary);
                            out.write((char*) money, sizeof(money));
                            out.close();
                            return 0;
                        }
                    }
                }
            }
        }
        std::cerr << "Not enough compatible bills!\n";
        return 1;
    }
}
