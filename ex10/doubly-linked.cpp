#include <iostream>
#include "doubly-linked.h"

List::List(){
    first = NULL;
}

List::~List(){}

void List::insert(int n){
    // Create the node
    Node *node = new Node();
    node->val = n;
    node->next = NULL;

    // Check if node is the first element
    if(first == NULL){
        first = node;
        node->prev = NULL;
        return;
    }

    // Insert the new node in the list end
    Node *current = first;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = node;
    node->prev = current;
    
}

void List::reverse(){
    Node *current = first;
    Node *temp = NULL;

    // Iterate to the last element swapping *next with *prev pointers
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Set the first element
    if(temp != NULL){
        first = temp->prev;
    }
}

void List::print(){
    Node *current = first;

    while(current != NULL){
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}