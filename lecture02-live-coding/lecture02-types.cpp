// Simple example on types, casting, overflows, and imprecision

#include <iostream>
#include <string>
#include <typeinfo>
#include <climits>

using namespace std;

// This is a function that takes an int argument (called x) and returns and int
int increment(int x) {
    return x + 1; // This will overflow if x == INT_MAX!
}

// This is a function that takes an int argument (called x) and returns and int
int check_increment(int x) {
    // A 'double' value can be larger than an 'int', so we can cast and compare
    if (((double)x + 1.0) > (double)INT_MAX) {
        // We have detected the overflow
        cout << "WARNING: overflow! ";
    }
    return x + 1;
}

// This is a function that takes no argument (void) and returns and int
int main(void) {
    // 'int' values range between INT_MAX and INT_MIN. They can overflow / underflow
    cout << "The maximum value of an integer is: " << INT_MAX << endl;
    cout << "The minimum value of an integer is: " << INT_MIN << endl;

    int n;
    cout << "Please give me the value of n: ";
    cin >> n;
    
    cout << "If we call increment(n), we get: " << increment(n) << endl;
    cout << "If we call check_increment(n), we get: " << check_increment(n) << endl;

    // We now show that floating-point values have precision limits
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    double result = (a + b) - c;

    cout << "Is (" << a << " + " << b << ") - " << c << " equal to 0.0? ";
    if (result == 0.0) {
        cout << "Yes!" << endl;
    } else {
        cout << "NO!!! It is equal to " << result << endl;
    }

    return 0;
}
