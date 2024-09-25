// Examples with arrays
#include <iostream>

using namespace std;

void sumArray(int n, int array[]) {
    //TODO: display the sum of the array elements
}

void printArray(int n, int array[]) {
    //TODO: show the contents of the array
}

int main() {
    ///////////////////////////////////////////////////////////////////////////
    // An array with contents specified at compile time
    // TODO: create array aGiven
    printArray(3, aGiven);
    sumArray(3, aGiven);

    cout << endl << endl;

    ///////////////////////////////////////////////////////////////////////////
    // An array of length specified at compile time
    // TODO: create array aLengthComp and instantiate its elements
	printArray(3, aLengthComp);
    sumArray(3, aLengthComp);

    cout << endl << endl;

    ///////////////////////////////////////////////////////////////////////////
    // An array of length specified at runtime
    int n = 0;
    cout << "Give me the size of the array:" << endl;
    cin >> n;

    // TODO: create array aLengthComp and instantiate its elements
	
    printArray(n, aLengthRun);
    sumArray(n, aLengthRun);

    return 0;
}
