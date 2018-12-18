#pragma once
#define BOARD_SIZE 8
class Piece
{
protected:
	char _name;
	int _xPos;
	int _yPos;
public:
	Piece(char name, int xPos, int yPos);
	virtual ~Piece();
	virtual int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) = 0;
	void move(Piece* board[][BOARD_SIZE], int xPos, int yPos);
};