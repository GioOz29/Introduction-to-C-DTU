// Examples with arrays
#include <iostream>

using namespace std;

void sumArray(int n, int array[]) {
    int sum = 0;
    for (int i = 0; i < n; i = i+1) {
        sum = sum + array[i];
    }
    cout << "The sum of the numbers in the array is " << sum << "\n";
}

void printArray(int n, int array[]) {
    cout << "The array contains:" << endl;
    for (int i = 0; i < n; i = i+1) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    ///////////////////////////////////////////////////////////////////////////
    // An array with contents specified at compile time
    int aGiven[] = { 3, 1, 2 };
    printArray(3, aGiven);
    sumArray(3, aGiven);

    cout << endl << endl;

    ///////////////////////////////////////////////////////////////////////////
    // An array of length specified at compile time
    int aLengthComp[3]; // We aren't specifying the array contents
    cout << "Give me the " << 3 << " numbers:" << endl;
    for (int i = 0; i < 3; i = i + 1) {
        cin >> aLengthComp[i];
    }
    printArray(3, aLengthComp);
    sumArray(3, aLengthComp);

    cout << endl << endl;

    ///////////////////////////////////////////////////////////////////////////
    // An array of length specified at runtime
    int n = 0;
    cout << "Give me the size of the array:" << endl;
    cin >> n;

    // This might work on some compilers, but it is NOT standard C++!
    // int aLengthRun[n]; // We aren't specifying the array contents

    int *aLengthRun = new int[n]; // Dynamically allocate an array of size n

    cout << "Give me the " << n << " numbers:" << endl;
    for(int i = 0; i < n; i = i + 1) {
        cin >> aLengthRun[i];
    }
    printArray(n, aLengthRun);
    sumArray(n, aLengthRun);

    delete[] aLengthRun; // Don't forget to deallocate the array when done!

    return 0;
}
