#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

const size_t NUMBER_OF_TREES(2);   // 5 trees
const size_t NUMBER_OF_LARGE_BRANCHES_MAX(2); // 3-5 main large branches.
const size_t NUMBER_OF_LARGE_BRANCHES_MIN(2);
const size_t NUMBER_OF_MIDDLE_BRANCHES_MAX(2); // 2-3 medium branches.
const size_t NUMBER_OF_MIDDLE_BRANCHES_MIN(2);

class Branch {
  public:
    Branch* parent;
    std::vector<Branch*> children;
    std::string elfName;

    Branch(const std::string&);
    
    ~Branch();

    std::string getElfName();

    void addChild(Branch*);
};