// Examples with arrays
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 42;
    int *p; // p can contain the address of an int value (but is uninitialised)

    p = &x; // Now p contains the memory address of x (written &x)

    // Difference: p (memory address) vs. *p (value stored at that address)
    cout << "The value of p is " << p << " and points to value " << *p << endl;

    p = &y; // Now p contains the memory address of y (written &y)

    cout << "The value of p is " << p << " and points to value " << *p << endl;

    ///////////////////////////////////////////////////////////////////////////
    // Pointers vs. arrays
    int a[] = {100, 101, 102};

    p = a; // Now p is equal to a, so it points to the beginning of the array

    cout << "The value of a is " << a << " and points to value " << a[0] << endl;
    cout << "The value of p is " << p << " and points to value " << *p << endl;

    // We can also index a pointer as if it was an array!
    cout << "p[0]=" << p[0] << " p[1]=" << p[1] << " p[2]=" << p[2] << endl;

    return 0;
}
