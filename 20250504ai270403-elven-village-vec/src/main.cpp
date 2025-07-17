#include "branch.h"
#include "forest.h"

#define DEBUG false

int main() {
    std::srand(std::time(nullptr));
    std::cout << "Hello!\n";

    Forest forest;
    std::cout << "That one matches forest -> " << &forest << "\n";
    std::cout << forest.root << "\n";
    forest.create();

    std::cout << "\tforest.root:\t" << forest.root << "\t" << forest.root->parent << "\t" << forest.root->getElfName() << "\t" << &forest.root->children << "\t" << forest.root->children.size() << "\n";
    for(size_t i(0); i < forest.root->children.size(); ++i) {
        std::cout << "\t\tTree # " << i
                  << "\t" << forest.root->children[i]
                  << "\t" << forest.root->children[i]->parent
                  << "\t" << forest.root->children[i]->getElfName()
                  << "\t" << &forest.root->children[i]->children
                  << "\t" << forest.root->children[i]->children.size()
                  << "\n";
        for(size_t j(0); j < forest.root->children[i]->children.size(); ++j) {
            std::cout << "\t\t\tLarge branch # " << j
                      << "\t" << forest.root->children[i]->children[j]
                      << "\t" << forest.root->children[i]->children[j]->parent
                      << "\t" << forest.root->children[i]->children[j]->getElfName()
                      << "\t" << &forest.root->children[i]->children[j]->children
                      << "\t" << forest.root->children[i]->children[j]->children.size()
                      << "\n";
        }
    }

#if DEBUG
    while (true) {
        std::string searchString;
        std::cout << "Введите строку для поиска (или 'exit' для выхода): ";
        std::cin >> searchString;

        if (searchString == "exit") break;

        forest.findVariable(searchString);
    }
#endif

    return 0;
}
