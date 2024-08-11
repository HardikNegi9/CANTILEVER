#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;

// 
class Product {
private:
    string id;
    string name;
    int quantity;
    double price;

public:
    Product();
    Product(string id, string name, int quantity, double price);
    string get_id() const;
    string get_name() const;
    int get_quantity() const;
    double get_price() const;
    void set_id(string id);
    void set_name(string name);
    void set_quantity(int quantity);
    void set_price(double price);
    void display_all() const;
};

#endif
