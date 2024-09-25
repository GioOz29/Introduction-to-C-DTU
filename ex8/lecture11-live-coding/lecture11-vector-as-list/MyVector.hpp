// Implementation of a vector clas using linked lists
#include <iostream>

using namespace std;

// The constructor
template<class T>
MyVector<T>::MyVector(void) {
    first = nullptr ;
}

// Destructor method
template<class T>
MyVector<T>::~MyVector<T>(void) {
    // We need to deallocate the linked list
    deallocate();
}

// Deallocate all elements of the vector, recursively
template<class T>
void MyVector<T>::deallocate(){
    deallocateR(first);
    first = nullptr;
}

template<class T>
void MyVector<T>::deallocateR(Node<T> *p) {
    if (p == nullptr) {
        return;
    } else {
        deallocateR(p->next);
        delete p;
    }
}

// size() implemented using recursion
template<class T>
unsigned int MyVector<T>::size(void) {
    return sizeR(first);
}

template<class T>
unsigned int MyVector<T>::sizeR(Node<T> *n) const {
    if (n == nullptr) {
        return 0;
    } else {
        return 1 + this->sizeR(n->next);
    }
}

// erase() implemented using recursion
template<class T>
void MyVector<T>::erase(unsigned int n) {
    eraseR(first, 0, n);
}

// Argument 'i' is the current element number, and 'n' is the element to erase
template<class T>
void MyVector<T>::eraseR(Node<T> *&p, unsigned int i, unsigned int n) {
    if (i == n) {
        // We need to remove the current node
        Node<T> *tmp = (*p).next; // Save a pointer to the next node
        delete p;
        p = tmp;
    } else {
        eraseR((*p).next, i+1, n);
    }
}

// push_back() implemented using recursion
template<class T>
void MyVector<T>::push_back(T x) {
    push_backR(x, first);
}

template<class T>
void MyVector<T>::push_backR(T x, Node<T> *&pp) {
    // check if first is nullptr
    // this means the either the list is empty
    // or we arrived to the end
    if (pp == nullptr){
        // create a new node for x
        Node<T> *p;
        p = new Node<T>;
        p->content = x;
        p->next = nullptr;
        // update first to point to the new element
        pp = p;
        return;
    }
    
    // otherwise, push back in the rest of the list
    push_backR(x, pp->next);
}

// Method "at" implemented with a loop
// It can of course be implemented with recursion as well
template<class T>
T MyVector<T>::at(unsigned int i) {
    // We check if we are accessing an actual element of the vector
    // otherwise we raise an error
    if (i >= this->size()) {
        throw std::out_of_range("Out-of-range access!");
    }
    
    // We iterate through the list until we find the i-th
    // element or we reach the end of the list
    unsigned int j = 0;
    for (Node<T> *p = first; p != nullptr; p = p->next) {
        if (j == i) {
            return p->content;
        }
        j = j + 1;
    }
    throw std::logic_error("BUG: this line should never be reached!");
}

// Here we overload the operator _[_] to access vector elements in array-style
template<class T>
T &MyVector<T>::operator[](unsigned int i) {
    if (i >= this->size()) {
        throw std::out_of_range("Out-of-range access!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    unsigned int j = 0;
    for (Node<T> *p = first; p != nullptr; p = p->next) {
        if (j == i) {
            return p->content;
        }
        j = j + 1;
    }
    throw std::logic_error("BUG: this line should never be reached!");
}

// A user-defined assignment operator
template<class T>
MyVector<T> &MyVector<T>::operator=(MyVector &v) {
    // Delete all elements of the internal list in the vector being overwritten
    deallocate();

    // Copy all elements form v's internal list
    for (unsigned int i = 0; i < v.size(); i++) {
        push_back(v[i]);
    }

    return *this;
}
