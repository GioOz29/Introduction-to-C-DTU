#include "MyVector.h"

#include <iostream>

// The constructor
MyVector::MyVector(void) {
    // We decide here to start with a small capacity
    this->capacity = 1;
    this->vsize = 0;
    // We allocate the space we need dynamically
    this->content = new int[this->capacity];
    return;
}

// The constructor
MyVector::MyVector(int initialCapacity) {
    // We decide here to start with a small capacity
    this->capacity = initialCapacity;
    this->vsize = 0;
    // We allocate the space we need dynamically
    this->content = new int[this->capacity];
    return;
}

// Destructor method
MyVector::~MyVector(void) {
    // We need to deallocate the array
    delete [] this->content;
    return;
}

void MyVector::resize() {
    // Save pointer to current array
    int *old_content = this->content;

    // Allocate new array: we try to double the current capacity
    this->capacity = this->capacity * 2;
    this->content = new int[this->capacity];

    // Copy content
    for (unsigned int i = 0; i < this->vsize; i++) {
        this->content[i] = old_content[i];
    }

    // Delete old array
    delete [] old_content;
}

unsigned int MyVector::size(void) {
    return this->vsize;
}

void MyVector::push_back(int x) {
    // Resize array if full
    if (this->vsize == this->capacity) {
        resize();
    }

    // Insert new element
    this->content[this->vsize] = x;
    this->vsize = this->vsize + 1;

}

int MyVector::at(unsigned int i) {
    // If we are accessing outside the last element, we raise an error
    if (i >= this->vsize){
        throw std::out_of_range("Access out of range");
    }
    return this->content[i];
}

// Here we overload the operator [_] to access MyVector elements in array-style
int & MyVector::operator[](unsigned int i) {
    if (i>=this->vsize) {
        throw std::out_of_range("Access out of range");
    }
    // Note that we do not return an element but a reference to an element (see return type)
    return this->content[i];
}

// Our custom assignment operator, needed to handle dynamic allocations
MyVector & MyVector::operator=(MyVector &v) {
    // The next 3 lines show what the default assignment operator = would do
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    // this->content = v.content; // Would be wrong: would just copy the pointer

    // Instead of copying a pointer, we want to deallocate our old contents...
    delete[] this->content;
    // ...allocate an array matching our capacity (which is also v's capacity)...
    this->content = new int[this->capacity];
    // ...and copy the contents of v
    for (unsigned int i=0; i < this->vsize; i++) {
        this->content[i] = v.content[i];
    }
    return * this;
}

