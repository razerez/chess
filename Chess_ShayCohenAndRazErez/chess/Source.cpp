#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Chess.h"

using namespace std;
void main()
{
	srand(time_t(NULL));
	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msg[2];
	msg[1] = NULL;
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbqkbnr################################################RNBQKBNR1"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	Chess myGame = Chess(msgToGraphics);
	myGame.printBoard();
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
 // msgToGraphics should contain the result of the operation
		msg[0] = myGame.handleInput(msgFromGraphics) + (int)'0';
		myGame.printBoard();
		// return result to graphics		
		p.sendMessageToGraphics(msg);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
}