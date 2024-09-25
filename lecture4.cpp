/*------------- MEMORY MANAGEMENT & POINTERS -------------
  --------------------------------------------------------
  -------------------- LECTURE 4 -------------------------
  --------------------------------------------------------
  ------------- BIDIMAENTSIONAL ARRAYS -------------------
*/

#include <iostream>

using namespace std;


int main(){
    int rows, cols;
    cout << "How many rows and cols?" << endl;
    cin >> rows >> cols;

    double **a = new double*[rows]; // Creating a pointer that point to the rows of the bidimentional array
    for(int i = 0; i < rows; i++){
        a[i] = new double[cols];    // Each value of the rows will point to another value on the columns
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> a[i][j];  // This means that each values has 2 addresses
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < rows; i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}