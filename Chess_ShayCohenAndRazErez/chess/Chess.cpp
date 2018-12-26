#include "Chess.h"
Piece* makeLetterToPiece(char letter, int xPos, int yPos)
{
	Piece* newPiece = 0;
	switch (letter)
	{
	case '#':
		newPiece = 0;
		break;
	case 'k':
		newPiece = new King('k', xPos, yPos);
		break;
	case 'r':
		newPiece = new Rook('r', xPos, yPos);
		break;
	case 'n':
		newPiece = new Kinght('n', xPos, yPos);
		break;
	case 'K':
		newPiece = new King('K', xPos, yPos);
		break;
	case 'R':
		newPiece = new Rook('R', xPos, yPos);
		break;
	case 'N':
		newPiece = new Kinght('N', xPos, yPos);
		break;
	default:
		newPiece = 0;
		break;
	}
	return newPiece;
}
Chess::Chess(string chessStr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			_board[BOARD_SIZE - i - 1][j] = makeLetterToPiece(chessStr[i*BOARD_SIZE + j],BOARD_SIZE - i - 1, j);
			if (chessStr[i*BOARD_SIZE + j] == 'k')
			{
				bKing = (King*)_board[BOARD_SIZE - i - 1][j];
			}
			else if (chessStr[i*BOARD_SIZE + j] == 'K')
			{
				wKing = (King*)_board[BOARD_SIZE - i - 1][j];
			}
		}
	}
	whiteTurn = false;
}
Chess::~Chess()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			delete this->_board[i][j];
		}
	}
}
int Chess::handleInput(string input)
{
	int oldyPos = input[0] - 'a';
	int oldxPos = input[1] - '1';
	int newyPos = input[2] - 'a';
	int newxPos = input[3] - '1';
	int codeError = 0;
	std::cout << "x:" << oldxPos << "y:" << oldyPos << std::endl;
	std::cout << "x:" << newxPos << "y:" << newyPos << std::endl;
	Piece* currPiece = _board[oldxPos][oldyPos];
	Piece* atePiece = 0;
	King* myKing = bKing;
	King* enemyKing = wKing;
	if (this->whiteTurn)
	{
		myKing = wKing;
		enemyKing = bKing;
	}
	if (currPiece && currPiece->isWhite() == this->whiteTurn)
	{
		codeError = currPiece->canMove(_board, newxPos, newyPos);
		if (!codeError)
		{
			std::cout << currPiece->getX() << " " << currPiece->getY() << std::endl;
			atePiece = currPiece->move(_board, newxPos, newyPos);
			if (myKing->check(_board))
			{
				currPiece->move(_board, oldxPos, oldyPos);
				codeError = 4;
				if (atePiece)
				{
					atePiece->move(_board, newxPos, newyPos);
				}
			}
			else if (enemyKing->check(_board))
			{
				codeError = 1;
			}
		}
	}
	else
	{
		codeError = 2;
	}
	if (codeError == 0 || codeError == 1)
	{
		whiteTurn = !whiteTurn;
	}
	return codeError;
}
void Chess::printBoard()
{
	int i = 0;
	int j = 0;
	for (i = BOARD_SIZE - 1; i >= 0; i--)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (this->_board[i][j])
			{
				std::cout << this->_board[i][j]->getName() << " ";
			}
			else
			{
				std::cout << 0 << " ";
			}
		}
		std::cout << std::endl;
	}
}