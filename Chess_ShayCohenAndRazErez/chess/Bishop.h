#pragma once
#include "Queen.h"
class Bishop : public Queen
{
public:
	Bishop(char name, int xPos, int yPos);
	~Bishop();
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
};