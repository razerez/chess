#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(char name, int xPos, int yPos);
	virtual ~Queen();
	//int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	bool canMoveVertically(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	//bool canMoveDiagonally(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	bool checkVerticle(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	//bool checkDiagonal(Piece* board[][BOARD_SIZE], int xPos, int yPos);
private:

};