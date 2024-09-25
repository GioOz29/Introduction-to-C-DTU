// An overview of C++

// By the way, everything written on the right of '//' is a comment :-)

/*
This is also a comment
that spans
across multiple lines
*/

#include <iostream> // Include the 'iostream' standard library
#include <string> // Include the 'string' standard library
#include <math.h> // Include the math library

using namespace std; // Avoid repeating 'std' in standard library symbols
                     // E.g., we can now write 'cout' instad of 'std::cout'

// Here we define a function that takes a string named 'op' and returns an int
// The function returns 0 when it ends correctly, and non-zero otherwise
int runOperation(string op) {
    if (op == "add") {
        cout << "Please write two numbers" << endl;
        int a, b;
        // Note: the numbers can be separated by spaces, tabs, newlines, ...
        cin >> a;
        cin >> b;
        int result = a + b;
        cout << "The result of " << a << "+" << b << " is " << result << endl;
        return 0; // Ended correcty
    } else if (op == "ceiling") {
        cout << "Please write a number" << endl;
        double x;
        cin >> x;
        cout << "The ceiling of " << x << " is " << ceil(x) << endl;
        return 0; // Ended correctly
    } else if (op == "sqrt") {
        cout << "Please write a number" << endl;
        double x;
        cin >> x;
        cout << "The square root of " << x << " is " << sqrt(x) << endl;
        return 0; // Ended correctly
    } else if (op == "factorial") {
        cout << "Please write a number" << endl;
        int n;
        cin >> n;

        int result = 1; // This variable will contain the factorial result

        // We now want to compute: n * (n-1) * (n-2) * ... * 2 * 1
        
        // An implementation using a 'while' loop
        /*
        int n2 = n; // A copy of n that we modify in the loop below
        while (n2 > 1) {
            result = n2 * result;
            n2 = n2 - 1; // We move to the next factor
        }
        */
        
        // An alternative implementation using a 'for' loop
        // The 'for' contains:
        //  1. an initialisation statement (in this case: declares 'int n2 = n')
        //  2. the loop repeat condition (in this case: 'n2 > 1')
        //  3. a statement executed after each loop (in this case: 'n2 = n2 - 1')
        for (int n2 = n; n2 > 1; n2 = n2 - 1) {
            result = n2 * result;
        }
        
        cout << "The factorial of " << n << " is " << result << endl;
        return 0; // Ended correctly
    } else {
        cout << "Sorry, I don't understand" << endl;
        return 1; // The operation was incorrect
    }
}

// This is the entry point of the program
int main() {
    cout << "Hej 02393!" << endl; // Outputs to the terminal, with newline
    
    string op; // Variable of type string. Will contain the user's choice below
    
    cout << "What operation would you like to perform?" << endl;
    cout << "Choose between: add, ceiling, sqrt, factorial" << endl;
    cin >> op; // Reads input from terminal, saves it in variable 'op'

    // Call function runOperation() and later use its return value as exit code
    int exitCode = runOperation(op);

    // When main() returns 0, it means that the program ended correctly
    return exitCode;
}
