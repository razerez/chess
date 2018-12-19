#pragma once
#include "Piece.h"
class King : public Piece
{
	King(char name, int xPos, int yPos);
	virtual ~King();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos);
};