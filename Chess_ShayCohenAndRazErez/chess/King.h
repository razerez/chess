#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(char name, int xPos, int yPos);
	virtual ~King();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
	bool check(Piece* board[][BOARD_SIZE]) const;
};