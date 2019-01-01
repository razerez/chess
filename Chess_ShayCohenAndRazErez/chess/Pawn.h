#pragma once
#include "Rook.h"
bool sameSign(int num1, int num2);
class Pawn : public Rook
{
private:
	bool _isMoved;
public:
	Pawn(char name, int xPos, int yPos);
	virtual ~Pawn();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos);
};