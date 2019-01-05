#include "Pawn.h"
Pawn::Pawn(char name, int xPos, int yPos) : Piece::Piece(name, xPos, yPos)
{
	this->_isMoved = false;
}
Pawn::~Pawn()
{

}
bool Pawn::sameSign(int num1, int num2)
{
	bool flag = false;
	if ((num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0))
	{
		flag = true;
	}
	return flag;
}
int Pawn::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) 
{
	int codeError = 0;
	int maxSteps = -2;
	if (this->_isMoved)
	{
		maxSteps = -1;
	}
	else if(this->isWhite())
	{
		maxSteps *= -1;
		if (xPos - this->_xPos > maxSteps)
		{
			codeError = 6;
		}
		else if(!((xPos == this->_xPos + 1 && yPos == this->_yPos + 1) || (xPos == this->_xPos + 1 && yPos == this->_yPos - 1) || (yPos == this->_yPos && xPos > this->_xPos)))
		{
			codeError = 6;
		}
		else if ((yPos == this->_yPos && xPos > this->_xPos))
		{
			if (!Piece::nullCheck(board, xPos, yPos))
			{
				codeError = 3;
			}
		}
		else if((xPos == this->_xPos + 1 && yPos == this->_yPos + 1) || (xPos == this->_xPos + 1 && yPos == this->_yPos - 1))
		{
			if(sameSign(xPos, yPos))
			{
				codeError = 3;
			}
		}
		else if (xPos - this->_xPos == 2)
		{
			if (!Piece::nullCheck(board, this->_xPos + 1, this->_yPos))
			{
				codeError = 6;
			}
		}
	}
	else
	{
		if (xPos + this->_xPos > maxSteps)
		{
			codeError = 6;
		}
		else if (!((xPos == this->_xPos - 1 && yPos == this->_yPos - 1) || (xPos == this->_xPos - 1 && yPos == this->_yPos + 1) || (yPos == this->_yPos && xPos < this->_xPos)))
		{
			codeError = 6;
		}
		else if ((yPos == this->_yPos && xPos < this->_xPos))
		{
			if (!Piece::nullCheck(board, xPos, yPos))
			{
				codeError = 3;
			}
		}
		else if ((xPos == this->_xPos - 1 && yPos == this->_yPos - 1) || (xPos == this->_xPos - 1 && yPos == this->_yPos + 1))
		{
			if (sameSign(xPos, yPos))
			{
				codeError = 3;
			}
		}
		else if (xPos - this->_xPos == 2)
		{
			if (!Piece::nullCheck(board, this->_xPos - 1, this->_yPos))
			{
				codeError = 6;
			}
		}
	}
	if(codeError == 0)
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	if (maxSteps == 2 && codeError == 0)
	{
		this->_isMoved = true;
	}
	return codeError;
}