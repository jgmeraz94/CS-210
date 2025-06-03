#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {

    ItemToPurchase item1;
    ItemToPurchase item2;
    string name;
    int price, quantity;

    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item1.SetName(name);

    cout << "Enter the item price:" << endl;
    cin >> price;
    item1.SetPrice(price);

    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    item1.SetQuantity(quantity);

    cin.ignore();

    cout << "\nItem 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item2.SetName(name);

    cout << "Enter the item price:" << endl;
    cin >> price;
    item2.SetPrice(price);

    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    item2.SetQuantity(quantity);

    cout << "\nTOTAL COST" << endl;
    int cost1 = item1.GetPrice() * item1.GetQuantity();
    int cost2 = item2.GetPrice() * item2.GetQuantity();

    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << cost1 << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << cost2 << endl;
    cout << "\nTotal: $" << (cost1 + cost2) << endl;

    return 0;
}