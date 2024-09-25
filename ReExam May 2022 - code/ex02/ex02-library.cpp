#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void shift(Passenger *q, unsigned int n) {
    // Write your code here
    if (q == nullptr) {
        return;
    }
    q->row += n;
    shift(q->next, n);
}

// Task 2(b).  Implement this function
Passenger* find(Passenger *q, unsigned int rowMin, unsigned int rowMax) {
    // Replace the following with your code
    Passenger* queue = nullptr;
    Passenger* tail = nullptr;
    if (q == nullptr) {
        return queue;
    }
    while (q != nullptr) {
        if (q->row >= rowMin && q->row <= rowMax) { //to ask why with rowMin <= q->row <= rowMax doesn't work
            // Create a dynamically allocated copy of the passenger
            Passenger* newpassenger = new Passenger;
            newpassenger->name = q->name;
            newpassenger->row = q->row;
            newpassenger->seat = q->seat;
            newpassenger->ticket = q->ticket;
            newpassenger->next = nullptr;

            if (queue == nullptr) {
                queue = newpassenger;
                tail = newpassenger;
            } else {
                tail->next = newpassenger;
                tail = newpassenger;
            }
        }

        q = q->next;  // Move to the next passenger in the original queue
    }
    return queue;
}

// Task 2(c).  Implement this function
bool occupied(Passenger *q, unsigned int row, char seat) {
    // Replace the following with your code
    Passenger* samerow = nullptr;
    samerow = find(q, row, row);

    while(samerow != nullptr){
        if(samerow->seat == seat){
            return true;
        }
        samerow = samerow->next;
    }
    return false;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    cout << ", seat " << q->row << q->seat << endl;
    displayQueue(q->next);
}
