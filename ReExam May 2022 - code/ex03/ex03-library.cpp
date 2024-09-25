#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::renameRoom(string oldName, string newName) {
    // Write your code here
    Guest g = roomOccupancy[oldName];   // save the value of guest in a variable temp
    replace(roomNames.begin(), roomNames.end(), oldName, newName);  // replace a value in a vector
    for(auto it:roomNames){
        if(it == newName){
            roomOccupancy[newName] = g; // if the replace take place than assign the guest in the room
        }
    }
}

// Task 3(b).  Implement this method
void Hotel::removeGuest(string roomName) {
    // Write your code here
    map<string,Guest>::iterator it1;
    for(auto it:roomNames){
        if(it == roomName && roomOccupancy.find(it) != roomOccupancy.end()){
            it1 = roomOccupancy.find(it);
            roomOccupancy.erase(it1);
        }
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuestId(vector<string> guestIds) {
    // Write your code here
    map<string,Guest>::iterator id;
    for(auto it1:guestIds){
        for(auto it:roomNames){
            if(it1 == roomOccupancy[it].id){
                cout << it << endl;
            }
        }
    }
    
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}

// g++ -std=c++20 ex03-main.cpp ex03-library.cpp ex03-library.h