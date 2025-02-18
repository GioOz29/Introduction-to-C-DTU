#include <iostream>
#include "ex01-library.h"
using namespace std;

int main() {
    Square **c = createChessboard(3);
    c[0][0].piece = bishop; c[0][0].team = white;
    c[0][2].piece = rook; c[0][3].team = white;
    c[2][0].piece = rook; c[2][0].team = black;
    c[2][1].piece = bishop; c[2][1].team = black;

    cout << "Chessboard:" << endl;
    displayChessboard(c, 3);

    cout << "Is the piece in (0,2) threatened? ";
    if (threatened(c, 3, 0, 2)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (0,0) to (1,0)? ";
    if (move(c, 3, 0, 0, 1, 0)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (2,0) to (2,1)? ";
    if (move(c, 3, 2, 0, 2, 1)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (2,0) to (0,0)? ";
    if (move(c, 3, 2, 0, 0, 0)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Can we move from (2,1) to (1,2)? ";
    if (move(c, 3, 2, 1, 1, 2)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << endl << "The chessboard is now:" << endl;
    displayChessboard(c, 3);

    cout << "Is the piece in (0,2) threatened? ";
    if (threatened(c, 3, 0, 2)) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    deleteChessboard(c, 3);
    return 0;
}
