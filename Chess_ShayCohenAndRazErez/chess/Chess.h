#pragma once
#include "King.h"
#include <iostream>
using std::string;
Piece* getPieceInLoction(int xPos, int yPos);
class Chess
{
public:
	Chess();
	~Chess();
	int handleInput(string input);
private:
	bool whiteTurn;
	Piece* _board[BOARD_SIZE][BOARD_SIZE];
	King* wKing;
	King* bKing;
};