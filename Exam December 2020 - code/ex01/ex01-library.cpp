#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    // Write your code here
    Complex **matrix = new Complex*[m];
    for(int i = 0; i<m; i++){
        matrix[i] = new Complex[n];
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = c;
        }
    }
    return matrix;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    // Write your code here
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << A[i][j].re;
            if(A[i][j].im>=0){
                cout << "+i" << abs(A[i][j].im);
            } else {
                cout << "-i" << abs(A[i][j].im);
            }
            cout << " ";
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Write your code here
    Complex C = {0,0};
    Complex **c = createMatrix(n, n, C);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                c[i][j].re = 1;
                c[i][j].im = 0;
            } else {
                c[i][j].re = 0;
                c[i][j].im = 0;
            }
        }
    }
    return c;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    // Write your code here
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            C[i][j] = {0, 0}; // Initialize the element in C to zero
            for(int k = 0; k<n; k++){
                Complex product = mult(A[i][k], B[k][j]);
                C[i][j] = add(C[i][j], product);
            }
        }
    }

}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
