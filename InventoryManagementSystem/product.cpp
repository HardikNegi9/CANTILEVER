#include "product.h"
#include <iostream>

Product::Product() : id(""), name(""), quantity(0), price(0.0) {}

Product::Product(std::string id, std::string name, int quantity, double price)
    : id(id), name(name), quantity(quantity), price(price) {}

std::string Product::get_id() const { return id; }
std::string Product::get_name() const { return name; }
int Product::get_quantity() const { return quantity; }
double Product::get_price() const { return price; }

void Product::set_id(std::string id) { this->id = id; }
void Product::set_name(std::string name) { this->name = name; }
void Product::set_quantity(int quantity) { this->quantity = quantity; }
void Product::set_price(double price) { this->price = price; }

void Product::display_all() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nQuantity: " << quantity << "\nPrice: " << price << std::endl;
}
