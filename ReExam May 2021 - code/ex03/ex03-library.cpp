#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList() {
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes) {
    // Write your code here
    for(auto it:items){
        if(name == it){
            itemsInfo[it].quantity += quantity;
            itemsInfo[it].notes += ";" + notes;
            break;
        }
    }
    items.push_back(name);
    itemsInfo[name].quantity = quantity;
    itemsInfo[name].notes = notes;
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity) {
    // Write your code here
    for(auto it:items){
        if(name == it){
            if(itemsInfo[it].quantity < quantity){
                return false;
            } else {
                itemsInfo[it].quantity -= quantity;
                if(itemsInfo[it].quantity<=0){
                    // need to remove the name from the vector items and the quantity and notes from the map itemsInfo
                    auto it1 = find(items.begin(), items.end(), name);
                    if(it1 != items.end()){
                        items.erase(it1);
                    }
                    itemsInfo.erase(it);
                }
                return true;
            }
        }
    }
    return false;
}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName) {
    // Write your code here
    auto it1 = find(items.begin(), items.end(), newName);   // check if newName is present inside the list
    for(auto it:items){
        if(it1 == items.end() && it == name){
            items.push_back(newName);
            itemsInfo[newName].quantity = itemsInfo[name].quantity;
            itemsInfo[newName].notes = itemsInfo[name].notes;
            return true;
        }
    }
    return false;
}

// Do not modify
void GroceryList::display() {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}