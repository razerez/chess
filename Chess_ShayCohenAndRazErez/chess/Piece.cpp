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
void Piece::move(Piece* board[][BOARD_SIZE], int xPos, int yPos)
{
	Piece* temp = board[this->_xPos][this->_yPos];
	board[this->_xPos][this->_yPos] = 0;
	this->_xPos = xPos;
	this->_yPos = yPos;
	board[this->_xPos][this->_yPos] = temp;
}