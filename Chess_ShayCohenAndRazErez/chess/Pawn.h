#pragma once
#include "Piece.h"
class Pawn : public Piece
{
private:
	bool _isMoved;
public:
	Pawn(char name, int xPos, int yPos);
	virtual ~Pawn();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	bool sameSign(int num1, int num2);
};