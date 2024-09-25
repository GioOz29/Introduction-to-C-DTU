// A few miscellaneous features and operators
#include <iostream>
#include <string>
using namespace std;

// Here define a preprocessor identifier: in the code below, every occurrence
// of MAXIMUM will be replaced by 10
#define MAXIMUM 10

int main() {
    // Below we use 'i++' as shorthand for 'i = i+1'
    for (int i = 0; i < MAXIMUM; i++) {
        // Conditional expression: if i is even, yields "even", otherwise "odd"
        string oddOrEven = ((i % 2) == 0) ? "even" : "odd";

        // Not using the conditional expression above would be more verbose...
        // if ((i % 2) == 0) {
        //     oddOrEven = "even";
        // } else {
        //     oddOrEven = "odd";
        // }

        cout << "The number " << i << " is " << oddOrEven << endl;
    }

  return 0;
}
