#pragma once
#define BOARD_SIZE 8
#include <iostream>
class Piece
{
protected:
	char _name;
	int _xPos;
	int _yPos;
public:
	Piece(char name, int xPos, int yPos);
	virtual ~Piece();
	virtual int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	Piece* move(Piece* board[][BOARD_SIZE], int xPos, int yPos);
	bool isWhite();
	bool sameColor(Piece& other);
	bool Piece::nullCheck(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
	char getName();
	int getX();
	int getY();
};