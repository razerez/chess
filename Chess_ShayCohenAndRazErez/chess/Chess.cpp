#include "Chess.h"
Piece* getPieceInLoction(int xPos, int yPos)
{
	Piece* newPiece = 0;
	if (xPos == 0)
	{
		if (yPos == 0 || yPos == 7)
		{
			newPiece = 0;
			//newPiece = new Rook();
		}
		else if (yPos == 1 || yPos == 6)
		{
			newPiece = 0;
			//newPiece = new Knight();
		}
		else if (yPos == 2 || yPos == 5)
		{
			//newPiece = new Bioshop();
			newPiece = 0;
		}
		else if (yPos == 3)
		{
			newPiece = new King('k', xPos, yPos);
		}
		else if (yPos == 4)
		{
			//newPiece = new Queen('q', xPos, yPos);
			newPiece = 0;
		}
		else
		{
			newPiece = 0;
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
			this->_board[i][j] = getPieceInLoction(i, j);
		}
	}
}
