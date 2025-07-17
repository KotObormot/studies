#include "forest.h"

#define DEBUG true

Forest::Forest(): root(nullptr) {
    //std::cout << "Created forest-> " << this << "\n";
}

Forest::~Forest() {
    //std::cout << "Deleted forest-> " << this << "\n";
    delete root;
}

void Forest::create() {
    root = new Branch("None");
    //std::cout << "That one matches root -> " << root << "\n";

    size_t numTrees(NUMBER_OF_TREES); // 5 trees
    std::cout << "There are "<< numTrees << " trees in the elven village.\n";
    for (size_t i(0); i < numTrees; ++i) {

        Branch* tree(new Branch("None"));
        std::cout << "That one matches tree #" << i << "-> " << tree << "\n";
        root->addChild(tree);

#if DEBUG
        size_t numLargeBranches(randomNumber(NUMBER_OF_LARGE_BRANCHES_MIN, NUMBER_OF_LARGE_BRANCHES_MAX));
        std::cout << "Tree # " << i << " has " << numLargeBranches << " large branches.\n";
        for (size_t j(0); j < numLargeBranches; ++j) {
            std::cout << "\t" << i << "." << j << ": What is the elf's name?--> ";
            std::string name;
            //getline(std::cin, name);
            std::cout << "\n";

            Branch* largeBranch(new Branch(name));
            //std::cout << "That one matches large branch #" << i << "." << j << "-> " << largeBranch << "\n";
            tree->addChild(largeBranch);

            size_t numMiddleBranches(randomNumber(NUMBER_OF_MIDDLE_BRANCHES_MIN, NUMBER_OF_MIDDLE_BRANCHES_MAX));
            std::cout << "\tLarge branch # " << j << " has " << numMiddleBranches << " middle branches.\n";
            for (size_t k(0); k < numMiddleBranches; ++k) {
                std::cout << "\t\t" << i << "." << j << "." << k << ": What is the elf's name?--> ";
                //getline(std::cin, name);
                std::cout << "\n";

                Branch* middleBranch(new Branch(name));
                //std::cout << "That one matches middle branch #" << i << "." << j << "." << k << "-> " << middleBranch << "\n";
                largeBranch->addChild(middleBranch);
            }
        }
#endif
    }
}

void Forest::search(const std::string& name, Branch* node, bool& found, std::vector<std::string>& childNames) {
    if (!node || found) return;

    if (node->elfName == name) {
        found = true;
        for (auto child : node->children) {
            childNames.push_back(child->elfName);
        }
        return;
    }

    for (auto child : node->children) {
        search(name, child, found, childNames);
    }
}

void Forest::findVariable(const std::string& name) {
    bool found = false;
    std::vector<std::string> childNames;
    
    search(name, root, found, childNames);

    if (found) {
        std::cout << "Переменная '" << name << "' найдена!" << "\n";
        if (!childNames.empty()) {
            std::cout << "Дочерние переменные: ";
            for (const auto& childName : childNames) {
                std::cout << childName << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Нет дочерних переменных." << "\n";
        }
    } else {
        std::cout << "Переменная '" << name << "' не найдена." << "\n";
    }
}

size_t Forest::randomNumber(size_t min, size_t max) {
    return (std::rand() % (max - min + 1)) + min;
}