#ifndef MYVECTOR_H_
#define MYVECTOR_H_

#include "linked-list.h"


template<class T>
class MyVector {
public:
    // Constructor method
    MyVector(void);
    // Destructor method
    ~MyVector(void);

    // Other useful methods
    unsigned int size(void);
    T at(unsigned int);
    T & operator[](unsigned int);
    void erase(unsigned int);
    void push_back(T);

    // User-defined assignment
    MyVector<T> & operator=(MyVector<T> &);;

private:
    // Private members - implementation details, not part of the public API

    // The vector is internally implemented as a linked list
    Node<int> *first;

    // Some internal methods
    unsigned int sizeR(Node<T> *n) const;
    void deallocate(void);
    void deallocateR(Node<T> *p);
    void eraseR(Node<T> *&p, unsigned int i, unsigned int n);
    void push_backR(T x, Node<T> *&p);
};

#include "MyVector.hpp"

#endif /* MYVECTOR_H_ */
