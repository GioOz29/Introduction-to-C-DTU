//============================================================================
// Name        : live03-vector.cpp
// Description : My own vector implementation, using templates
//============================================================================

#include <iostream>
#include "MyVector.h"

using namespace std;

int main(void) {
    // We declare a vector
    MyVector<int> v;

    // We insert some numbers using push_back
    for (unsigned int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // We access and manipulate some vector elements in array-style
    for (unsigned int i = 2; i < v.size(); i++) {
        v[i] = v[i-1] + v[i-2];
    }

    // We access some elements usint at()
    cout << "Vector after initialization: " << endl;
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    MyVector<int> v2;
    // We set b to be equal to a
    v2 = v;
    cout << "Result of assignment v2 = v: " << endl ;
    for (unsigned int i=0; i < v2.size(); i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    cout << "Erasing the 3rd element of v2..." << endl;
    v2.erase(2);
    cout << "Current contents of v2: " << endl ;
    for (unsigned int i=0; i < v2.size(); i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    return 0;
}
