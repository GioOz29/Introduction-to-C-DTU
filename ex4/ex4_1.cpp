#include <iostream>

using namespace std;

enum material{ wood, stone } ;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

// display the playground, showing also the player
void display(tile **playground, int rows, int cols, int x, int y){
    for(int i=0; i < rows; i++){
        for(int j=0; j< cols; j++){
            if(i == y && j == x){
                cout << "O";
            } else {
                switch (playground[i][j].type){
                    case stone:
                     cout << "*";
                     break;
                    case wood:
                     cout << " ";
                     break;
                }
            }
        }
        cout << endl;
    }
}

# define rows 12
#define cols 16

int main() {
    tile **playground = new tile*[rows];
    for(int i=0; i < rows; i++){
        playground[i] = new tile[cols];
    }
    // set up the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(rows-1) || (i==0 && j!=3) || j==(cols-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    // set up the initial position of the player
    int x = 5, y = 5;

    // Display the initial maze
    display(playground, rows, cols, x, y);

    char input;
    while(true){
        cin >> input;
        if(input == 'q'){
            break;
        } else if(input == 'l' && x > 0 && !playground[y][x-1].isWall){
            x--;
        } else if(input == 'r' && x < cols-1 && !playground[y][x+1].isWall){
            x++;
        } else if(input == 'u' && y > 0 && !playground[y-1][x].isWall){
            y--;
        } else if(input == 'd' && y < rows-1 && !playground[y+1][x].isWall){
            y++;
        }
        display(playground,rows,cols,x,y);
    }

    // delete everything 
    for(int i=0; i < rows; i++){
        delete[] playground[i];
    }
    delete[] playground;

    return 0;
}

// g++ ex4_1.cpp
// ./a.out