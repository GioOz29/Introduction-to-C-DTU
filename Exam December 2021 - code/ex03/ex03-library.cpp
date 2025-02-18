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
void Hotel::addRoom(string name) {
    // Write your code here
    for(auto it:roomNames){
        if(it == name){
            break;
        }
    }
    roomNames.push_back(name);
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    // Write your code here
    for(auto it:roomNames){
        if(it == roomName){
            if(roomOccupancy.find(roomName) == roomOccupancy.end()){
                roomOccupancy[roomName] = {guestName, guestId};
            }
        }
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    // Write your code here
    vector<string> occupiedbyg;
    if(guestName == "*" && guestId == "*"){
        for(auto it:roomNames){
            if(roomOccupancy.find(it) != roomOccupancy.end()){
                occupiedbyg.push_back(it);
            }
        }
    } else if (guestName != "*" && guestId == "*"){
        for(auto it:roomNames){
            if(roomOccupancy[it].name == guestName){
                occupiedbyg.push_back(it);
            }
        }
    } else if (guestName != "*" && guestId != "*"){
        for(auto it:roomNames){
            if(roomOccupancy[it].name == guestName && roomOccupancy[it].id == guestId){
                occupiedbyg.push_back(it);
            }
        }
    }
    for(auto it:occupiedbyg){
        cout << it << endl;
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
