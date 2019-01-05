#include "Queen.h"
Queen::Queen(char name, int xPos, int yPos) : Piece::Piece(name, xPos, yPos)
{
}
Queen::~Queen()
{
}
int Queen::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const
{
	int codeError = 0;
	if (!canMoveVertically(board, xPos, yPos) && !canMoveDiagonally(board, xPos, yPos))
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	return codeError;
}


bool Queen::canMoveVertically(Piece* board[][BOARD_SIZE], int xPos, int yPos) const//check if the location is vertical to the current place if true: call checkVerticle and return its return value| else: return false
{
	bool retVal = false;
	if ((xPos == this->_xPos && yPos != this->_yPos) || (yPos == this->_yPos && xPos != this->_xPos)) //if new place is dirctly above or dirctly beside current place
	{
		retVal = checkVerticle(board, xPos, yPos);
	}
	return retVal;
}


bool Queen::checkVerticle(Piece* board[][BOARD_SIZE], int xPos, int yPos) const
{
	bool retVal = true;
	if (xPos > this->_xPos)
	{
		for (size_t x = this->_xPos + 1; x < xPos; x++)
		{
			retVal = Piece::nullCheck(board, x, this->_yPos);
			if (retVal == false)
			{
				x = xPos;
			}
		}
	}
	else if (xPos < this->_xPos)
	{
		for (size_t x = this->_xPos - 1; x > xPos; x--)
		{
			retVal = Piece::nullCheck(board, x, this->_yPos);
			if (retVal == false)
			{
				x = xPos;
			}
		}
	}
	else if (yPos > this->_yPos)
	{
		for (size_t y = this->_yPos + 1; y < yPos; y++)
		{
			retVal = Piece::nullCheck(board, this->_xPos, y);
			if (retVal == false)
			{
				y = yPos;
			}
		}
	}
	else if (yPos < this->_yPos)
	{
		for (size_t y = this->_yPos - 1; y > yPos; y--)
		{
			retVal = Piece::nullCheck(board, this->_xPos, y);
			if (retVal == false)
			{
				y = yPos;
			}
		}
	}
	return retVal;
}


bool Queen::canMoveDiagonally(Piece* board[][BOARD_SIZE], int xPos, int yPos) const//check if the location is diagonal to the current place if true: call canMoveDiagonally and return its value| else: return false
{
	bool retVal = false;
	if (abs(this->_xPos - xPos) == abs(this->_yPos - yPos)) //if new place is diagonal to the current place
	{
		retVal = checkDiagonal(board, xPos, yPos);
	}
	return retVal;
}


bool Queen::checkDiagonal(Piece* board[][BOARD_SIZE], int xPos, int yPos) const
{
	bool retVal = false;
	if (xPos > this->_xPos && yPos > this->_yPos)
	{
		for (size_t i = 1; this->_xPos + i < xPos && this->_yPos + i < yPos; i++)
		{
			retVal = Piece::nullCheck(board, this->_xPos + i, this->_yPos + i);
			if (retVal == false)
			{
				i = xPos;
			}
		}
	}
	else if (xPos < this->_xPos && yPos > this->_yPos)
	{
		for (size_t i = 1; this->_xPos - i > xPos && this->_yPos + i < yPos; i++)
		{
			retVal = Piece::nullCheck(board, this->_xPos - i, this->_yPos + i);
			if (retVal == false)
			{
				i = yPos;
			}
		}
	}
	else if (xPos > this->_xPos && yPos < this->_yPos)
	{
		for (size_t i = 1; this->_xPos + i < xPos && this->_yPos - i > yPos; i++)
		{
			retVal = Piece::nullCheck(board, this->_xPos + i, this->_yPos - i);
			if (retVal == false)
			{
				i = xPos;
			}
		}
	}
	else if (xPos < this->_xPos && yPos < this->_yPos)
	{
		for (size_t i = 1; this->_xPos - i > xPos && this->_yPos - i > yPos; i++)
		{
			retVal = Piece::nullCheck(board, this->_xPos - i, this->_yPos - i);
			if (retVal == false)
			{
				i = xPos;
			}
		}
	}
	return retVal;
}


