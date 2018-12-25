#include "Piece.h"
Piece::Piece(char name, int xPos, int yPos)
{
	this->_name = name;
	this->_xPos = xPos;
	this->_yPos = yPos;
}
Piece::~Piece()
{	
}
char Piece::getName()
{
	return this->_name;
}

int Piece::canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	int codeError = 0;
	Piece* newPlace = board[xPos][yPos];
	if (newPlace && this->sameColor(*newPlace))
	{
		codeError = 3;
	}
	else if (xPos > 8 || xPos < 0 || yPos > 8 || yPos < 0)
	{
		codeError = 5;
	}
	else if (xPos == this->_xPos && yPos == this->_yPos)
	{
		codeError = 7;
	}
	return codeError;
}

int Piece::getX()
{
	return this->_xPos;

}
int Piece::getY()
{
	return this->_yPos;
}
Piece* Piece::move(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	Piece* tempPiece1 = board[this->_xPos][this->_yPos];
	Piece* targetPiece = board[xPos][yPos];
	board[this->_xPos][this->_yPos] = 0;
	this->_xPos = xPos;
	this->_yPos = yPos;
	board[this->_xPos][this->_yPos] = tempPiece1;
	return targetPiece;
}
bool Piece::isWhite()
{
	bool flag = false;
	if (this->_name >= 'A' && this->_name <= 'Z')
	{
		flag = true;
	}
	return flag;
}
bool Piece::sameColor(Piece& other)
{
	bool flag = false;
	if (this->isWhite() == other.isWhite())
	{
		flag = true;
	}
	return flag;
}
bool Piece::nullCheck(Piece* board[][BOARD_SIZE], int xPos, int yPos) const
{
	bool retVal = true;
	if (board[xPos][yPos] != NULL)
	{
		retVal = false;
	}
	return retVal;
}