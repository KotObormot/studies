#include "branch.h"

Branch::Branch(const std::string& name): parent(nullptr), children(0), elfName(name) {
    //std::cout << "Created Branch-> " << this << "\n";
}
    
Branch::~Branch() {
    //for(auto child : children) {
    //    std::cout << "Deleted branch-> " << this << " : " << child << "\n";
    //    delete child;
    //}
    for(size_t i(0); i < children.size(); ++i) {
        //std::cout << "Deleted branch-> " << this << " : " << children[i] << "\n";
        delete children[i];
    }
}

void Branch::addChild(Branch* child) {
    children.push_back(child);
}

std::string Branch::getElfName() {
    std::string nameTMP{};
    for (size_t i(0); i < elfName.size(); ++i)  {
        nameTMP += std::tolower(elfName[i]);
    }
    if (nameTMP != "none") {
        return elfName;
    } else {
        return /*"The house is not inhabited."*/"THINI";
    }
}

