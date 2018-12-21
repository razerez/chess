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
	if (!(abs(this->_xPos - xPos) <= 1 && abs(this->_yPos - yPos) <= 1))
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
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