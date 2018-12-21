#include "Chess.h"
Piece* getPieceInLoction(int xPos, int yPos)
{
	Piece* newPiece = 0;
	if (xPos == 0)
	{
		switch (yPos)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}
	return newPiece;
}
Chess::Chess()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			this->_board[i][j] = new 
		}
	}
}
