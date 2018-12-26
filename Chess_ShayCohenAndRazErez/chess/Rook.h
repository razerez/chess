#include "Queen.h"


class Rook : public Queen
{
public:
	Rook(char name, int xPos, int yPos);
	~Rook();
private:
	int canMove(Piece* board[][BOARD_SIZE], int xPos, int yPos) const;
};