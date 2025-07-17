#pragma once
#include "branch.h"

class Forest {
  private:
    size_t randomNumber(size_t, size_t);
  public:
    Branch* root;
  public:
    Forest();
    ~Forest();

    void create();

    void search(const std::string&, Branch*, bool&, std::vector<std::string>&);

    void findVariable(const std::string& name);

};
