#ifndef iostream
#include <iostream>
#endif

typedef unsigned long long U64;


class ChessBoard
{
public:
    U64 pieceBB[14] = {0};
    U64 emptyBB;
    U64 occupiedBB;
    enum Piece
    {
        white,
        black,
        wPawn,
        bPawn,
        wRook,
        bRook,
        wKnight,
        bKnight,
        wBishop,
        bBishop,
        wQueen,
        bQueen,
        wKing,
        bKing
    };

    static void printState(ChessBoard board);
    

    void static printBitBoard(U64 bb);
    
    // Bit number and physical row and column map
    // Rank 8 | 56 57 58 59   60 61 62 63
    // Rank 7 | 48 49 50 51   52 53 54 55
    // Rank 6 | 40 41 42 43   44 45 46 47
    // Rank 5 | 32 33 34 35   36 37 38 39
    // Rank 4 | 24 25 26 27   28 29 30 31
    // Rank 3 | 16 17 18 19   20 21 22 23
    // Rank 2 |  8  9 10 11   12 13 14 15
    // Rank 1 |  0  1  2  3    4  5  6  7
    //         ------------   -----------
    //          a  b  c  d    e  f  g  h

    ChessBoard static setNewState(ChessBoard board);
    
};