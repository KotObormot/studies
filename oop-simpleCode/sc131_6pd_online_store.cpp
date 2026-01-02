// https://www.youtube.com/watch?v=nZNcRRXeKTk&t=430s
// online store

#include <iostream>
#include <memory>
#include <unordered_map>

class Product {
  public:
    Product(int id) {
        // Долгие запросы к БД
        // и заполнение полей данными
        std::cout << id << ": Long queries to the database and filling fields with data\n";
    }
};

std::unique_ptr<const Product> loadProdact(int id) {
    return std::make_unique<const Product>(id);
}

std::shared_ptr<const Product> fastLoadProduct(int id) {
    static std::unordered_map<int, std::weak_ptr<const Product>> cashe;
    std::shared_ptr<const Product> objPtr = cashe[id].lock();
    if(!objPtr) {
        objPtr = loadProdact(id);
        cashe[id] = objPtr;
    }
    return objPtr;
}

int main() {
    
    return 0;
}