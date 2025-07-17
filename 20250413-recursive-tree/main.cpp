//https://www.youtube.com/watch?v=z1aQjQ3hncI&list=PLD075A4D416004C91&index=4
#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    Tree<int>* tree =
        new Tree<int>(1,
            new Tree<int>(2, NULL,
            new Tree<int>(3,
                new Tree<int>(5, NULL,
                new Tree(6,
                    new Tree<int>(8, NULL,
                    new Tree<int>(9, NULL,
                    new Tree<int>(10))))),
            new Tree<int>(4,
                new Tree<int>(7)))));
    cout << "Tree height: " << tree->GetHeight() << "\n";
    delete tree;

    return 0;
}