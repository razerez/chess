#include "Kinght.h"
Kinght::Kinght(char name, int xPos, int yPos) : Piece::Piece(name,xPos,yPos)
{

}
Kinght::~Kinght()
{

}
int Kinght::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const
{
	int codeError = 0;
	if(!((abs(this->_yPos - yPos) == 1 && abs(this->_xPos - xPos) == 2)  || (abs(this->_xPos - xPos) == 1 && abs(this->_yPos - yPos) == 2)))
	{
		codeError = 6;
	}
	else
	{
		codeError = Piece::canMove(board, xPos, yPos);
	}
	return codeError;
}