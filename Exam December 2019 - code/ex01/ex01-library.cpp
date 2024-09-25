#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	//put your code here
	cell **board = new cell*[n];
	for(int i = 0; i < n; i++){
		board[i] = new cell[n];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(0 <= i && i < 3){
				board[i][j].color = computeColor(i,j);
				if(board[i][j].color == dark){
					board[i][j].status = blackPiece;
				}
			} else if(n-3 <= i && i < n){
				board[i][j].color = computeColor(i,j);
				if(board[i][j].color == bright){
					board[i][j].status = whitePiece;
				}
			} else{
				board[i][j].color = computeColor(i,j);
				board[i][j].status = emptyC;
			}
		}
	}
	return board;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	//put your code here
	cell **board = new cell*[n];
	for(int i = 0; i < n; i++){
		board[i] = new cell[n];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[i][j].color = A[i][j].color;
			board[i][j].status = A[i][j].status;
		}
	}
	return board;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){
	//put your code here
	int new_r, new_c;
	if(A[r][c].status == blackPiece){
		new_r = r + 1;
		new_c = c - 1;
	} else if(A[r][c].status == whitePiece){
		new_r = r - 1;
		new_c = c + 1;
	} else return false;

	if(r<0 || r>=n || c<0 || c>=n || new_r<0 || new_r>=n || new_c<0 || new_c>=n){
		return false;
	}
	A[new_r][new_c].status = A[r][c].status;
	A[r][c].status = emptyC;
	return true;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	//put your code here
	int new_r, new_c;
	if(A[r][c].status == blackPiece){
		new_r = r + 1;
		new_c = c + 1;
	} else if(A[r][c].status == whitePiece){
		new_r = r - 1;
		new_c = c - 1;
	} else return false;

	if(r<0 && r>=n || c<0 && c>=n || new_r<0 || new_r>=n || new_c<0 || new_c>=n){
		return false;
	}
	A[new_r][new_c].status = A[r][c].status;
	A[r][c].status = emptyC;
	return true;
}

//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	std::cout << ' ';
	for(int c=0;c<n;c++){
		std::cout << c;
	}
	std::cout << endl;
	for(int r=0;r<n;r++){
		std::cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				std::cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				std::cout << "W";
				break;
			case blackPiece:
				std::cout << "B";
				break;
			}
		}
		std::cout << endl;
	}
	std::cout << endl;
}
