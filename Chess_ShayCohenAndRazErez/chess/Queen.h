#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(char name, int xPos, int yPos);
	virtual ~Queen();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
	bool canMoveVertically(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
	bool canMoveDiagonally(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
	bool checkVerticle(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
	bool checkDiagonal(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
private:

};