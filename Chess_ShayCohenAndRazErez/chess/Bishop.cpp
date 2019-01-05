#include "Bishop.h"


Bishop::Bishop(char name, int xPos, int yPos) : Queen::Queen(name, xPos, yPos)
{
}


Bishop::~Bishop()
{
}


int Bishop::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const
{
	int codeError = 0;
	if (!Queen::canMoveDiagonally(board, xPos, yPos))
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	return codeError;
}