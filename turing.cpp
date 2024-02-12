// turing.cpp : Defines the entry point for the application.
//

#include "turing.h"
#include "ChessBoard.h"
using namespace std;

int main()
{
	ChessBoard cb;
	cb = ChessBoard::setNewState(cb);
	ChessBoard::printState(cb);
	// ChessBoard::printBitBoard(cb.pieceBB[5]);
}
