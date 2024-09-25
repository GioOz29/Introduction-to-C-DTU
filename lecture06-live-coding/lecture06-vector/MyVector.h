#ifndef MYVECTOR_H_
#define MYVECTOR_H_

class MyVector {

public:
    // Constructor methods
    MyVector(void);
    MyVector(int initialCapacity);

    // Destructor method
    ~MyVector(void);

    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);

    // User-defined assignment
    MyVector & operator=(MyVector &);

private:
    // Private members
    // Used to implement the class, not meant for the user
    int *content;
    unsigned int vsize;
    unsigned int capacity;
    void resize(void);
};

#endif /* MYVECTOR_H_ */
