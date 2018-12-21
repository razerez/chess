#include "King.h"
King::King(char name, int xPos, int yPos) : Piece::Piece(name, xPos, yPos)
{

}
King::~King()
{
}
int King::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	int codeError = 0;
	Piece* newPlace = board[xPos][yPos];
	if (!(abs(this->_xPos - xPos) <= 1 && abs(this->_yPos - yPos)))
	{
		codeError = 6;
	}
	if (xPos > 8 || xPos < 0 || yPos >8 || yPos < 0)
	{
		codeError = 5;
	}
	else if(newPlace && this->sameColor(*newPlace))
	{
		codeError = 3;
	}
	else if (xPos == this->_xPos && yPos == this->_yPos)
	{
		codeError = 7;
	}
	return codeError;
}
bool King::check(Piece* board[][BOARD_SIZE])
{
	int i = 0;
	int j = 0;
	bool check = false;
	for (i = 0; i < BOARD_SIZE && !check; i++)
	{
		for (j = 0; j < BOARD_SIZE && !check; j++)
		{
			if (board[i][j]->canMove(board, this->_xPos, this->_yPos))
			{
				check = true;
			}
		}
	}
	return check;
}