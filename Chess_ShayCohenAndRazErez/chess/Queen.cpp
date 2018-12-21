#include "Queen.h"
Queen::Queen(char name, int xPos, int yPos) : Piece::Piece(name, xPos, yPos)
{
}
Queen::~Queen()
{
}
int Queen::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	int codeError = 0;
	if (!verticle || !diagonal)
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	return codeError;
}


bool Queen::verticle(Piece* board[][BOARD_SIZE], int xPos, int yPos)//check if the location is vertical to the current place if true: call canMoveVertically and return its value| else: return false
{
	bool retVal = false;
	if ((xPos == this->_xPos && yPos != this->_yPos) || (yPos == this->_yPos && xPos == this->_xPos)) //if new place is dirctly above or dirctly beside current place
	{
		retVal = canMoveVertically(board, xPos, yPos);
	}
	return retVal;
}


bool Queen::canMoveVertically(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	bool retVal = true;
	if (xPos > this->_xPos)
	{
		for (size_t x = this->_xPos + 1; x < xPos; x++)
		{
			retVal = nullCheck(board, x, this->_yPos);
		}
	}
	else if (xPos < this->_xPos)
	{
		for (size_t x = this->_xPos - 1; x > xPos; x--)
		{
			retVal = nullCheck(board, x, this->_yPos);
		}
	}
	else if (yPos > this->_yPos)
	{
		for (size_t y = this->_yPos + 1; y < yPos; y++)
		{
			retVal = nullCheck(board, this->_xPos, y);
		}
	}
	else if (yPos < this->_yPos)
	{
		for (size_t y = this->_yPos - 1; y > yPos; y--)
		{
			retVal = nullCheck(board, this->_xPos, y);
		}
	}
	return retVal;
}


bool nullCheck(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	bool retVal = true;
	if (board[xPos][yPos] != NULL)
	{
		retVal = false;
	}
	return retVal;
}


bool Queen::diagonal(Piece* board[][BOARD_SIZE], int xPos, int yPos)//check if the location is diagonal to the current place if true: call canMoveDiagonally and return its value| else: return false
{
	//bool retVal = false;
	//if (abs(this->_xPos - xPos) == abs(this->_yPos - yPos)) //if new place is dirctly above or dirctly beside current place
	//{
	//	retVal = canMoveVertically(board, xPos, yPos);
	//}
	//return retVal;
}


