#include "ex04-library.h"
#include <iostream>

//Do not modify
Piece::~Piece(){}

//Do not modify
void Piece::printPosition(){
	cout << "(" << r << "," << c << ")" << endl;
}

//Exercise 4 (a) implement methods of WhitePiece
//put your code here
WhitePiece::WhitePiece(int row, int col){
	r = row;
	c = col;
}

string WhitePiece::getColor(){
	return "white";
}
string WhitePiece::printCode(){
	return "W";
}

void WhitePiece::moveRight(){
	r -= 1;
	c += 1;
}

void WhitePiece::moveLeft(){
	r -= 1;
	c -= 1;
}

//Exercise 4 (b) implement methods of BlackPiece
//put your code here
BlackPiece::BlackPiece(int row, int col){
	r = row;
	c = col;
}

string BlackPiece::getColor(){
	return "black";
}
string BlackPiece::printCode(){
	return "B";
}

void BlackPiece::moveRight(){
	r += 1;
	c -= 1;
}

void BlackPiece::moveLeft(){
	r += 1;
	c += 1;
}