// https://www.youtube.com/watch?v=5GsIxgI1Ri8&list=PLA0M1Bcd0w8x4jEp1r_aN3xlnlbfx9RQ2&index=9&t=616s
#include "StructuresData.hpp"

int main() {
    OneLinkedList lst;
    lst.push_front(1.1);
    lst.push_back(2.2);
    for(double i(0); i < 10; ++i) {
        lst.push_back(i + i / 10);
    }

    for(Node* node = lst.head; node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
    std::cout << "\n";
    return 0;
}