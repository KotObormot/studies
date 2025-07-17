#include <iostream>
#include <vector>
#include <string>
//#include <cstdlib>
#include <ctime>

class TreeNode {
public:
    std::string name;
    std::vector<TreeNode*> children;

    TreeNode(const std::string& name) : name(name) {}
    
    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

class Tree {
private:
    TreeNode* root;

public:
    Tree() : root(nullptr) {}

    void createTree() {
        root = new TreeNode("Root");

        int numBranches = rand() % 3 + 5; // от 5 до 7 больших веток
        for (int i = 0; i < numBranches; ++i) {
            std::string branchName;
            std::cout << "Введите имя для большой ветки " << (i + 1) << ": ";
            std::cin >> branchName;

            TreeNode* bigBranch = new TreeNode(branchName);
            root->addChild(bigBranch);

            int numMediumBranches = rand() % 3 + 3; // от 3 до 5 средних веток
            for (int j = 0; j < numMediumBranches; ++j) {
                std::string mediumBranchName;
                std::cout << "Введите имя для средней ветки " << (j + 1) << " большой ветки " << branchName << ": ";
                std::cin >> mediumBranchName;

                TreeNode* mediumBranch = new TreeNode(mediumBranchName);
                bigBranch->addChild(mediumBranch);

                int numSmallBranches = rand() % 3 + 2; // от 2 до 4 малых веток
                for (int k = 0; k < numSmallBranches; ++k) {
                    std::string smallBranchName;
                    std::cout << "Введите имя для малой ветки " << (k + 1) << " средней ветки " << mediumBranchName << ": ";
                    std::cin >> smallBranchName;

                    TreeNode* smallBranch = new TreeNode(smallBranchName);
                    mediumBranch->addChild(smallBranch);
                }
            }
        }
    }

    void search(const std::string& name, TreeNode* node, bool& found, std::vector<std::string>& childNames) {
        if (!node || found) return;

        if (node->name == name) {
            found = true;
            for (auto child : node->children) {
                childNames.push_back(child->name);
            }
            return;
        }

        for (auto child : node->children) {
            search(name, child, found, childNames);
        }
    }

    void findVariable(const std::string& name) {
        bool found = false;
        std::vector<std::string> childNames;
        
        search(name, root, found, childNames);

        if (found) {
            std::cout << "Переменная '" << name << "' найдена!" << std::endl;
            if (!childNames.empty()) {
                std::cout << "Дочерние переменные: ";
                for (const auto& childName : childNames) {
                    std::cout << childName << " ";
                }
                std::cout << std::endl;
            } else {
                std::cout << "Нет дочерних переменных." << std::endl;
            }
        } else {
            std::cout << "Переменная '" << name << "' не найдена." << std::endl;
        }
    }

    ~Tree() {
        delete root;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    Tree tree;
    tree.createTree();

    while (true) {
        std::string searchString;
        std::cout << "Введите строку для поиска (или 'exit' для выхода): ";
        std::cin >> searchString;

        if (searchString == "exit") break;

        tree.findVariable(searchString);
    }

    return 0;
}