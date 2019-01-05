#pragma once
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Kinght.h"
#include "Pawn.h"
#include <iostream>
using std::string;
Piece* makeLetterToPiece(char letter, int xPos, int yPos);
class Chess
{
public:
	Chess(string chessStr);
	~Chess();
	int handleInput(string input);
	void printBoard();
private:
	bool whiteTurn;
	Piece* _board[BOARD_SIZE][BOARD_SIZE];
	King* wKing;
	King* bKing;
};