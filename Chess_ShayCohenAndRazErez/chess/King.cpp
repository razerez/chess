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
	if (!(abs(this->_xPos - xPos) <= 1 && abs(this->_yPos - yPos)))
	{
		
	}
}