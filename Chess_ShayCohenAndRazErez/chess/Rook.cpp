#include "Rook.h"


Rook::Rook(char name, int xPos, int yPos) : Queen::Queen(name, xPos, yPos)
{
}


Rook::~Rook()
{
}


int Rook::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	int codeError = 0;
	if (!Queen::canMoveVertically(board, xPos, yPos))
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	return codeError;
}