#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void displayTeams(TournamentNode *t) {
    // Write your code here
    if(t == nullptr){
        return;
    }
    if(t->nodeType == match){
        displayTeams(t->left);
        displayTeams(t->right);
    }
    if(t->nodeType == team){
        cout << t->name << endl;
    }
}

// Task 2(b).  Implement this function
unsigned int matches(TournamentNode *t) {
    // Replace the following with your code
    if(t == nullptr || t->nodeType == team){
        return 0;
    }
    return 1 + matches(t->left) + matches(t->right);
}

// Task 2(c).  Implement this function
string winner(TournamentNode *t) {
    // Replace the following with your code
    if(t == nullptr){
        return "";
    }

    if(t->nodeType == team){
        return t->name;
    }

    if(t->result == leftWin){
        return winner(t->left);
    } else if(t->result == rightWin){
        return winner(t->right);
    } else return "";
}

// Task 2(d). Implement this function
bool wonAnyMatch(TournamentNode *t, string teamName) {
    // Replace the following with your code
    if(t == nullptr){
        return false;
    }
    if(t->nodeType == match){
        bool left = wonAnyMatch(t->left, teamName);
        bool right = wonAnyMatch(t->right, teamName);
        if(t->left->name == teamName && t->result == leftWin){
            return true;
        } else if(t->right->name == teamName && t->result == rightWin){
            return true;
        } else if(left == true || right == true){
            return true;
        }
    }
    return false;
}