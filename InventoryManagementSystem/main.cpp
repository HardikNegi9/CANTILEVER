#include<iostream>
using namespace std;
#include "inventory.h"

    void menu() {
        cout << endl;
        cout << "1. Add New Product\n";
        cout << "2. Update Product Details\n";
        cout << "3. Delete Product\n";
        cout << "4. View All Products\n";
        cout << "5. Generate Report\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }




int main() {
    int choice;
    Inventory inventory;
    do {
        menu();
        cin >> choice;
        cout << endl;
        string id, name;
        int quantity;
        double price;
        switch (choice){
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin >> name;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: ";
                cin >> price;
                inventory.add_p(Product(id, name, quantity, price));
                break;
            case 2:
                cout << "Enter Product ID to Update: ";
                cin >> id;
                inventory.update_p(id);
                break;
            case 3:
                cout << "Enter Product ID to Delete: ";
                cin >> id;
                inventory.del_p(id);
                break;
            case 4:
                inventory.view_all_p();
                break;
            case 5:
                inventory.report();
                break;
            case 6:
                cout << "Exited Succesfully\n";
                break;
            default:
                cout << "Invalid Input!, Enter again: ";
                break;
        }
    }while(choice != 6);

    return 0;
}