#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board {
    public:
        //Should initialize the board as 8x8 with all pieces in starting position
        Board();

        //Destructor
        ~Board();

        //Should reset board back to base state (pretty much exact same as constructor,
        // could prob be used for that actually)
        void resetBoard();

        //Should return pointer to piece at given location, Null if empty
        Piece* getPiece(int row, int col) const;

        //Should take start location and end location, then get the piece and from that
        // check if that move is valid for the piece, then it will procede to move the piece.
        //return true if move worked, false if failed
        bool movePiece(int sRow, int sCol, int eRow, int eCol);

        //Should print the current state of the board using the piece symbols and including the side numbers and letters
        /* Example Print Board (colors looked flipped because of dark mode)
          a b c d e f g h
        8 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
        7 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟ 
        6
        5
        4
        3
        2 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
        1 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖      
        */
        void printBoard() const;

        bool isWhiteKingAlive() const;
        bool isBlackKingAlive() const;

        
    private:
        Piece* board_[8][8];
        bool isWhiteKingAlive_;
        bool isBlackKingAlive_;

        //Helper: checks if position is inside board
        bool inBounds(int row, int col) const;

        //Helper: deletes all pieces (used in reset + destructor)
        void clearBoard();
};

#endif
