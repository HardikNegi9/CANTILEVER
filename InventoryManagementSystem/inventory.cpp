#include "inventory.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

Inventory::Inventory() {
    loadFromFile();
}

void Inventory::loadFromFile() {
    ifstream file("data.txt");
    if (file.is_open()) {
        string id, name;
        int quantity;
        double price;
        while (file >> id >> name >> quantity >> price) {
            products.emplace_back(id, name, quantity, price);
        }
        file.close();
    }
}

void Inventory::saveToFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (const auto& product : products) {
            file << product.get_id() << " " << product.get_name() << " " << product.get_quantity() << " " << product.get_price() << endl;
        }
        file.close();
    }
}

void Inventory::add_p(const Product& product) {
    products.push_back(product);
    saveToFile();
}

void Inventory::update_p(const string& id) {
    auto it = find_if(products.begin(), products.end(),
                      [&](const Product& product) {
                          return product.get_id() == id;
                      });

    if (it == products.end()) {
        cout << "Product with ID " << id << " not found in the inventory.\n";
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter New Product Name: ";
    cin >> name;
    cout << "Enter New Quantity: ";
    cin >> quantity;
    cout << "Enter New Price: ";
    cin >> price;

    // Update the found product
    it->set_name(name);
    it->set_quantity(quantity);
    it->set_price(price);

    saveToFile();
    cout << "Product with ID " << id << " has been updated successfully.\n";
}


void Inventory::del_p(const string& id) {
    auto it = find_if(products.begin(), products.end(), 
                      [&](const Product& product) {
                          return product.get_id() == id;
                      });

    if (it == products.end()) {
        cout << "Product with ID " << id << " not found in the inventory.\n";
        return;
    }

    cout << "Product Found!\n";
    cout << "ID: " << it->get_id() << endl;
    cout << "Name: " << it->get_name() << endl;
    cout << "Quantity: " << it->get_quantity() << endl;
    cout << "Price: " << it->get_price() << endl;

    cout << "Confirm deletion (y/n): ";
    char ch;
    cin >> ch;

    if (ch == 'y' || ch == 'Y') {
        products.erase(it);
        saveToFile();
        cout << "Product with ID " << id << " has been deleted successfully.\n";
    } else {
        cout << "Deletion canceled.\n";
    }
}


void Inventory::view_all_p() const {
    cout << "Displaying All Product Present :\n";
    for (const auto& product : products) {
        product.display_all();
        cout << endl;
    }
}

void Inventory::report() const {
    cout << "Inventory Report\n";
    for (const auto& product : products) {
        product.display_all();
        cout << endl;
    }
}
