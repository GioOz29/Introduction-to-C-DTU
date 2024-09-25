#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    // Replace the following with your code
    Square **board = new Square*[n];
    for(int i=0; i<n; i++){
        board[i] = new Square[n];
    }
    // generate the board
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j].piece = none;
            board[i][j].team = nobody;
        }
    }
    return board;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    // Write your code here
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            switch(c[i][j].piece){
                case none:
                    cout << "_";
                    break;
                case rook:
                    if(c[i][j].team == black){
                        cout << "R";
                    } else cout << "r";
                    break;
                case bishop:
                    if(c[i][j].team == black){
                        cout << "B";
                    } else cout << "b";
                    break;
            }
            cout << " ";
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n, int r1, int c1, int r2, int c2) {
    // Replace the following with your code
    Piece p = none;
    Team t = nobody;
    int k, l;
    int x_dist = abs(r2-r1);
    int y_dist = abs(c2-c2);

    // if the values are out of bound
    if(r1 < 0 || r1 > n || r2 < 0 || r2 > n || c1 < 0 || c1 > n || c2 < 0 || c2 > n || (r1 == r2 && c1 == c2)){
        return false;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==r1 && j==c1){
                if(c[i][j].piece!=none){
                    p = c[i][j].piece;
                    t = c[i][j].team;
                    k = i;
                    l = j;
                } else return false;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==r2 && j==c2){
                if(c[i][j].team!=t && p == rook && ((r1==r2)||(c1==c2))){
                    c[k][l].piece = none;
                    c[k][l].team = nobody;
                    c[i][j].piece = p;
                    c[i][j].team = t;
                    return true;
                } else if(c[i][j].team!=t && p == bishop && x_dist == y_dist){
                    c[k][l].piece = none;
                    c[k][l].team = nobody;
                    c[i][j].piece = p;
                    c[i][j].team = t;
                    return true;
                } else return false;
            }
        }
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n, int row, int col) {
    // Replace the following with your code
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(c[i][j].piece != none && move(c, n, i, j, row, col) == true){
                return true;
            } else return false;
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
