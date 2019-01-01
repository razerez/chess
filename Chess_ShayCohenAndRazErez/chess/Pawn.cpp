#include "Pawn.h"
bool sameSign(int num1, int num2)
{
	bool flag = false;
	if ((num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0))
	{
		flag = true;
	}
	return flag;
}
Pawn::Pawn(char name, int xPos, int yPos) : Rook::Rook(name, xPos, yPos)
{
	_isMoved = false;
}
Pawn::~Pawn()
{

}
int Pawn::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) 
{
	int codeError = 0;
	int maxSteps = -2;
	if (this->_isMoved)
	{
		maxSteps = -1;
	}
	if (this->isWhite())
	{
		maxSteps *= -1;
	}
	if(!(sameSign((xPos - this->_xPos),maxSteps) && abs(xPos - this->_xPos) <= abs(maxSteps) || !(abs(xPos - this->_xPos) == 1 && abs(yPos - this->_yPos) == 1 && !(this->sameColor(*board[xPos][yPos])))))//TOCO: fix here call me for help
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	if (maxSteps == 2 && !codeError)
	{
		this->_isMoved = true;
	}
	return codeError;
}