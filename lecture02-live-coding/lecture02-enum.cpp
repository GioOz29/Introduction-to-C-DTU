// Example using enumerations
#include <iostream>
#include <string>
using namespace std;

enum Direction {
    NORTH, // Underlying value: 0
    EAST,  // Underlying value: 1
    SOUTH, // Underlying value: 2
    WEST   // Underlying value: 3
};

// Function prototypes: they only specify the function name,
// the argument(s) type(s), and the return type, so they are known in main().
// The actual function definitions appear later
Direction turnLeft(Direction dir);
Direction turnRight(Direction dir);
string dirToText(Direction dir);

int main() {
    Direction dir = NORTH;

    while (true) {
        char turn;
        cout << "Now going " << dirToText(dir) << endl;
        cout << "Turn right (r), turn left (l), or quit (q): ";
        cin >> turn;
        if (turn == 'r') {
            cout << "Turning right" << endl;
            dir = turnRight(dir);
        } else if (turn == 'l') {
            cout << "Turning left" << endl;
            dir = turnLeft(dir);
        } else {
            cout << "Bye!" << endl;
            break;
        }
    }

    return 0;
}

/**
 * Return the direction to the left of the given direction.
 * Don't forget to use 'break' statements in the 'switch'!
 */
Direction turnLeft(Direction dir) {
    Direction newDir;
    // Don't forget to use 'break' statements in the 'switch'!
    switch (dir) {
        case NORTH:
            newDir = WEST;
            break;
        case WEST:
            newDir = SOUTH;
            break;
        case SOUTH:
            newDir = EAST;
            break;
        case EAST:
            newDir = NORTH;
            break;
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            newDir = NORTH;
            break;
    }
    return newDir;
}

/**
 * Return the direction to the right of the given direction.
 */
Direction turnRight(Direction dir) {
    switch (dir) {
        case NORTH:
            return EAST;
        case WEST:
            return NORTH;
        case SOUTH:
            return WEST;
        case EAST:
            return SOUTH;
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            return NORTH;
    }
}

/**
 * Return a string representation of the given direction
 */
string dirToText(Direction dir) {
    switch (dir) {
        case NORTH:
            return "North";
        case WEST:
            return "West";
        case SOUTH:
            return "South";
        case EAST:
            return "East";
        default:
            cout << "WARNING: invalid direction: " << dir << endl;
            return "INVALID!";
    }
}
