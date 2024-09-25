#ifndef MYVECTOR_H_
#define MYVECTOR_H_


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
	T *content;
    unsigned int vsize;
    unsigned int capacity;
    void resize(void);
};

#include "MyVector.hpp"

#endif /* MYVECTOR_H_ */
