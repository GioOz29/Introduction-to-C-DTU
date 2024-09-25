#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    // Write your code here
    if(list == nullptr || list->next == nullptr) return list;

    Elem* reversedList = reverse(list->next);
    list->next->next = list;
    list->next = nullptr;
    return reversedList;
}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    // Write your code here
    // If either list is empty, return the other list
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    // find the last element of list1
    if(list1->value == list2->value){
        // If the values are the same, update the times of repetition
        list1->times += list2->times;
        list1->next = concatenate(list1->next, list2->next);
    } else {
        // If the values are different, append list 2 to list 1
        list1->next = concatenate(list1->next, list2);
    }
    return list1;
}

// Task 2(c).  Implement this function
int sum(Elem *list) {
    // Write your code here
    if(list == nullptr) return 0;

    // Add the value of the current element to the sum of the rest of the list
    return list->value * list->times + sum (list->next);
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
