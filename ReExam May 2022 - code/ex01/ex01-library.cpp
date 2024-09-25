#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int m, unsigned int n) {
    // Replace the following with your code
    Square **board = new Square*[m];
    for(int i=0; i<m;i++){
        board[i] = new Square[n];
    }
    // Generate the board
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            board[i][j].piece = none;
            board[i][j].team = nobody;
        }
    }
    return board;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int m, unsigned int n) {
    // Write your code here
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            switch(c[i][j].piece){
                case none:
                    cout << "_";
                    break;
                case king:
                    if(c[i][j].team == black){
                        cout << "K";
                    } else cout << "k";
                    break;
                case queen:
                    if(c[i][j].team == black){
                        cout << "Q";
                    } else cout << "q";
                    break;
            }
            cout << " ";
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int m, unsigned int n, int r1, int c1, int r2, int c2) {
    // Replace the following with your code
    Piece p = none;
    Team t = nobody;
    int k, l;
    int x_dist = abs(r2 - r1);
    int y_dist = abs(c2 - c1);

    // if the values are out of bound
    if(r1 < 0 || r1 > m || r2 < 0 || r2 > m || c1 < 0 || c1 > n || c2 < 0 || c2 > n || (r1 == r2 && c1 == c2)){
        return false;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == r1 && j == c1){
                // save the info of the piece and the team
                if(c[i][j].piece != none){
                    p = c[i][j].piece;
                    t = c[i][j].team;
                    k = i;
                    l = j;
                } else return false; // the piece is none
            }
        }
    }

    // check the information on the second point
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == r2 && j == c2){
                if(c[i][j].team != t && p == king && x_dist <= 1 && y_dist <= 1){
                    c[k][l].team = nobody;
                    c[k][l].piece = none;
                    c[i][j].team = t;
                    c[i][j].piece = p;
                    return true;
                } else if (c[i][j].team != t && p == queen && (x_dist == y_dist || r1 == r2 || c1 == c2)){
                    c[k][l].team = nobody;
                    c[k][l].piece = none;
                    c[i][j].team = t;
                    c[i][j].piece = p;
                    return true;
                } else return false;    // the movement is not allowed
            }
        }
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int m, unsigned int n, int row, int col) {
    // Replace the following with your code
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(c[i][j].piece != none && move(c, m, n, i, j, row, col) == true){
                return true;
            } else return false;
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
