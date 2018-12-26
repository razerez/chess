#pragma once
#include "Piece.h"
class Kinght : public Piece
{
public:
	Kinght(char name, int xPos, int yPos);
	virtual ~Kinght();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
};