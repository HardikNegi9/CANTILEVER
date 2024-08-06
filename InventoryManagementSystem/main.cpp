#include<iostream>
#include "inventory.h"
using namespace std;

    void menu() {
        cout << "1. Add New Product\n";
        cout << "2. Update Product Details\n";
        cout << "3. Delete Product\n";
        cout << "4. View All Products\n";
        cout << "5. Generate Report\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }




int main() {
    Inventory inventory;
    int choice;

    do {
        menu();
        cin >> choice;

        if (choice == 1) {
            string id, name;
            int quantity;
            double price;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Price: ";
            cin >> price;
            inventory.add_p(Product(id, name, quantity, price));
        } else if (choice == 2) {
            string id, name;
            int quantity;
            double price;
            cout << "Enter Product ID to Update: ";
            cin >> id;
            cout << "Enter New Product Name: ";
            cin >> name;
            cout << "Enter New Quantity: ";
            cin >> quantity;
            cout << "Enter New Price: ";
            cin >> price;
            inventory.update_p(id, Product(id, name, quantity, price));
        } else if (choice == 3) {
            string id;
            cout << "Enter Product ID to Delete: ";
            cin >> id;
            inventory.del_product(id);
        } else if (choice == 4) {
            inventory.view_all_p();
        } else if (choice == 5) {
            inventory.report();
        }
    } while (choice != 6);

    return 0;
}