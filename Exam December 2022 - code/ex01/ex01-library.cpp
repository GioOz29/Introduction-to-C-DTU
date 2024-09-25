#include <iostream>
#include <random>
#include "ex01-library.hpp"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    // Replace the following with your code
    Tile **cavern = new Tile*[m];
    for(int i=0; i<m; i++){
        cavern[i] = new Tile[n];
    }
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            cavern[i][j].content = nothing;
            cavern[i][j].explored = false;
        }
    }
    return cavern;
}

// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Write your code here
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            switch(cav[i][j].content){
                case nothing:
                    cout << " ";
                    break;
                case rock:
                    cout << "#";
                    break;
                case wumpus:
                    cout << "W";
                    break;
                case player:
                    cout << "X";
                    break;
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    // Replace the following with your code
    if(r<m && 0<r && c<n && 0<c){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(cav[i][j].content == player){
                    double distance = sqrt(pow(r-i,2) + pow(c-j,2));
                    if(distance<5){
if(cav[r][c].content == nothing){
                        cav[i][j].content = nothing;
                        cav[r][c].content = player;
                        return true;
}
                    }
                }
            }
        }
    }
    return false;
}

// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Write your code here
    int pos_x = 0; int pos_y = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(cav[i][j].content == player){
                pos_x = i;
                pos_y = j;
                break;
            } 
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            double distance = sqrt(pow(i-pos_x,2) + pow(j-pos_y,2));
            if(distance<4){
                cav[i][j].explored = true;
            }
            if(!cav[i][j].explored){
                cout << "?";
            } else {
                switch(cav[i][j].content){
                    case nothing:
                        cout << "-";
                        break;
                    case rock:
                        cout << "#";
                        break;
                    case wumpus:
                        cout << "W";
                        break;
                    case player:
                        cout << "X";
                        break;
                }
            }
                    }
        cout << endl;
    }
}

// Do not modify the following function.
// This code (that you don't need to read) places the player
// at location (0,0) and pseudo-randomly places some rocks
// and a Wumpus. The pseudo-random placement depends on the
// value of 'seed'.
void setupCavern(Tile **cav, unsigned int m, unsigned int n, unsigned int seed) {
    mt19937 e; // Pseudo-random number generator
    e.seed(seed);

    // 1/3rd of the tiles are rocks
    unsigned int rocks = (m * n) / 3;
    for (unsigned int i = 0; i < rocks; i++) {
        cav[e()%m][e()%n].content = rock;
    }

    // We never place the Wumpus on row 0 or column 0
    unsigned int row = (e() % (m-1)) + 1;
    unsigned int col = (e() % (n-1)) + 1;
    cav[row][col].content = wumpus;

    cav[0][0].content = player;
}

// Do not modify the following function.
void deleteCavern(Tile **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
