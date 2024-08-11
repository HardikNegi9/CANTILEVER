#ifndef INVENTORY_H
#define INVENTORY_H

#include "product.h"
#include <vector>

class Inventory {
private:
    vector<Product> products;

    void loadFromFile();
    void saveToFile();

public:
    Inventory();

    void add_p(const Product& product);
    void update_p(const string& id);
    void del_p(const string& id);
    void view_all_p() const;
    void report() const;
};

#endif
