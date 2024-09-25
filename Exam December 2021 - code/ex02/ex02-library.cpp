#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    // Replace the following with your code
    Passenger* queue = nullptr;
    Passenger* tail = nullptr;
    if(q == nullptr) return queue;
    while(q!=nullptr){
        if(q->ticket == ticket){
            Passenger* newpassenger = new Passenger;
            newpassenger->name = q->name;
            newpassenger->ticket = q->ticket;
            newpassenger->priority = q->priority;
            newpassenger->next = nullptr;

            if(queue == nullptr){
                queue = newpassenger;
                tail = newpassenger;
            } else {
                tail->next = newpassenger;
                tail = newpassenger;
            }
        }
        q = q->next;
    }
    return queue;
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    // Replace the following with your code
    Passenger* current = q;
    Passenger* previous = nullptr;
    while(current!=nullptr){
        if(current->ticket == ticket){
            if(previous!=nullptr){
                previous->next = current->next;
            } else q = current->next;
        }
        previous = current;
        current = current->next;
    }
    return q;
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    // Replace the following with your code
    Passenger* queue = nullptr;
    Passenger* tail = nullptr;
    while(q!=nullptr){
        if(q->priority){
            Passenger* p = new Passenger;
            p->name = q->name;
            p->priority = q->priority;
            p->ticket = q->ticket;
            p->next = nullptr;
            if(queue == nullptr){
            queue = p;
            tail = p;
            } else {
                tail->next = p;
                tail = p;
            }
        }
        q = q->next;
    }
    return queue;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
