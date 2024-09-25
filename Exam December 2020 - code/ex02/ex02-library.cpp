#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    // Write your code here
    if(list == nullptr){
        return 0;
    }else {
        return list->times + length(list->next);
    }
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    // Write your code here
    if(list == nullptr){
        Elem *nElem = new Elem;
        nElem->value = v;
        nElem->times = 1;
        nElem->next = nullptr;
        return nElem;
    } else if(list->value == v){
        list->times++;
        return list;
    } else {
        list->next = append(list->next, v);
        return list;
    }
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    // Write your code here
    Elem *list = nullptr;
    for(int i = 0; i<n ; i++){
        list = append(list, data[i]);
    }
    return list;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
