#ifndef PIECE_H
#define PIECE_H

#include <string>

//Forward declaration so we can use board here, but board.h will be Board header file
class Board;

class Piece {
    public:
        //Constructor, just takes bool (true = white, false = black)
        Piece(bool isWhite);

        //Destructor, since we are likely to use pointers for this
        virtual ~Piece();

        //Should return unicode symbol for whatever piece it is, pure virtual since should be piece specific
        virtual std::string getSymbol() const = 0;

        // Should return if a move is possible or not, takes the board as well as the starting location and ending
        // location to check for valid moves
        virtual bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const = 0;

    protected:
        bool isWhite_;
};

class Pawn : public Piece {
    public:
        //Ctor just needed to pass iswhite up to piece
        Pawn(bool isWhite);
        
        //Should return either ♙ or ♟
        std::string getSymbol() const;

        //Should check for valid move based off of Pawn move logic (only go up, optionally 2 spaces on first move,
        // diagonal up if enemy)

        bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const;

    private:
        //Used to check to see if Pawn can move twice up or not
        bool hasMoved_;
};

class Rook : public Piece {
    public:
        //Ctor just needed to pass iswhite up to piece
        Rook(bool isWhite);

        //Should return either ♖ or ♜
        std::string getSymbol() const;

        //Should check for valid move based off of Rook move logic (left, right, up, down, straight line
        // until wall or enemy, might include castling but not necessary )
        bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const;
};

class Knight : public Piece {
    public:
        //Ctor just needed to pass iswhite up to piece
        Knight(bool isWhite);

        //Should return either ♘ or ♞
        std::string getSymbol() const;

        //Should check for valid move based off of Knight move logic (L, straight in any direction 2,
        // then 1 on either side)
        bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const;
};

class Bishop : public Piece {
    public:
        //Ctor just needed to pass iswhite up to piece
        Bishop(bool isWhite);

        //Should return either ♗ or ♝
        std::string getSymbol() const;

        //Should check for valid move based off of Bishop move logic (diagonal movement in any direction until,
        // wall or enemy)
        bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const;
};

class Queen : public Piece {
    public:
        //Ctor just needed to pass iswhite up to piece
        Queen(bool isWhite);

        //Should return either ♕ or ♛
        std::string getSymbol() const;

        //Should check for valid move based off of Queen move logic (bishop + rook move logic)
        bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const;
};

class King : public Piece {
    public:
        //Ctor just needed to pass iswhite up to piece
        King(bool isWhite);

        //Should return either ♔ or ♚
        std::string getSymbol() const;

        //Should check for valid move based off of King move logic (1 space in any direction)
        bool getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const;
};
#endif