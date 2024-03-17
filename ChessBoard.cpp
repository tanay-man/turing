
#include"ChessBoard.h"

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

    static void printState(ChessBoard board)
    {

        for (int row = 7; row >= 0; row--)
        { // Loop from rank 8 to rank 1
            std::cout << row + 1 << "   ";
            for (int column = 0; column < 8; column++)
            {
                bool pieceFound = false;
                for (int piece = 2; piece < 14; piece++)
                {
                    if ((board.pieceBB[piece] >> (row * 8 + column)) & 1)
                    {
                        // Piece found, print its symbol
                        switch (static_cast<Piece>(piece))
                        {
                        case wPawn:
                            std::cout << "P ";
                            break;
                        case bPawn:
                            std::cout << "p ";
                            break;
                        case wRook:
                            std::cout << "R ";
                            break;
                        case bRook:
                            std::cout << "r ";
                            break;
                        case wKnight:
                            std::cout << "N ";
                            break;
                        case bKnight:
                            std::cout << "n ";
                            break;
                        case wBishop:
                            std::cout << "B ";
                            break;
                        case bBishop:
                            std::cout << "b ";
                            break;
                        case wQueen:
                            std::cout << "Q ";
                            break;
                        case bQueen:
                            std::cout << "q ";
                            break;
                        case wKing:
                            std::cout << "K ";
                            break;
                        case bKing:
                            std::cout << "k ";
                            break;
                        }
                        pieceFound = true;
                        break; // Break out of the piece loop once the piece is found
                    }
                }
                if (!pieceFound)
                {
                    std::cout << ". "; // Print a dot for an empty square
                }
            }
            std::cout << std::endl; // Move to the next rank after printing a full row
        }
        char col_label = 'A';
        std::cout << "\n    ";
        for (int i = 0; i < 8; i++)
        {
            std::cout << col_label << " ";
            col_label++;
        }
        std::cout << "\n";
    }

    void static printBitBoard(U64 bb)
    {
        for (int row = 7; row >= 0; row--)
        { // Loop from rank 8 to rank 1
            std::cout << row + 1 << "   ";
            for (int column = 0; column < 8; column++)
            {
                U64 bit_pos = 8 * row + column;
                U64 mask = 1;
                mask = mask << bit_pos;
                if (bb & mask)
                {
                    std::cout << "1 ";
                }
                else
                {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
    }
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

    ChessBoard static setNewState(ChessBoard board)
    {
        board.pieceBB[white] = 0x000000000000ffff;
        board.pieceBB[black] = 0xffff000000000000;
        board.pieceBB[wPawn] = 0x000000000000ff00;
        board.pieceBB[bPawn] = 0x00ff000000000000;
        board.pieceBB[wRook] = 0x0000000000000081;
        board.pieceBB[bRook] = 0x8100000000000000;
        board.pieceBB[wKnight] = 0x000000000000042;
        board.pieceBB[bKnight] = 0x4200000000000000;
        board.pieceBB[wBishop] = 0x0000000000000024;
        board.pieceBB[bBishop] = 0x2400000000000000;
        board.pieceBB[wQueen] = 0x0000000000000008;
        board.pieceBB[bQueen] = 0x1000000000000000;
        board.pieceBB[wKing] = 0x0000000000000010;
        board.pieceBB[bKing] = 0x0800000000000000;
        
        return board;
    }
};