#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createSea(unsigned int m, unsigned int n) {
    Tile **sea = new Tile*[m];
    for(int i=0; i<m; i++){
        sea[i] = new Tile[n];
    }
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            sea[i][j].ship = 0;
            sea[i][j].hit = false;
        }
    }
    return sea;
}


// Task 1(b).  Implement this function
void displaySea(Tile **sea, unsigned int m, unsigned int n, bool reveal) {
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(reveal){
                if(sea[i][j].ship == 0){
                    cout << " ";
                } else if(sea[i][j].ship != 0 && sea[i][j].hit == false){
                    cout << sea[i][j].ship;
                } else if(sea[i][j].ship != 0 && sea[i][j].hit == true){
                    cout << "X";
                }
            } else {
                if(sea[i][j].ship != 0 && sea[i][j].hit == true){
                    cout << "X";
                } else if(sea[i][j].ship == 0 && sea[i][j].hit == true){
                    cout << " ";
                } else cout << "?";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool placeShip(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c, unsigned int number, unsigned int size, bool vertical) {
    //check ship size
    if (size < 1 || size > 4) {
        return false;
    }

    //chek ship position and for overlap or same number
    for (unsigned int i = 0; i < size; ++i) {
        //check if vertical
        unsigned int row;
        unsigned int col;
        if(vertical){
            row = r + i;
            col = c + 0;
        } else {
            row = r + 0;
            col = c + i;
        }
        
        //check if the position is out of bounds or already occupied
        if (row >= m || col >= n || sea[row][col].ship != 0) {
            return false;
        }
    }

    //check if there is already a ship with that number
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (sea[i][j].ship == number) {
                return false;
            }
        }
    }

    //place the ship
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int row = r + (vertical ? i : 0);
        unsigned int col = c + (vertical ? 0 : i);

        sea[row][col].ship = number;
    }
    return true;
}

// Task 1(d).  Implement this function
bool launchMissile(Tile **sea, unsigned int m, unsigned int n, unsigned int r, unsigned int c){
    //check if the coordinates are within the grid
    if (r >= m || c >= n) {
        return false;
    }

    Tile &targetTile = sea[r][c];

    //check if ship already hit
    if (targetTile.hit) {
        return false;
    }
    // set the sip to hit
    targetTile.hit = true;
    return true;
}

// Do not modify the following function.
void deleteSea(Tile **sea, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] sea[i];
    }
    delete[] sea;
}
