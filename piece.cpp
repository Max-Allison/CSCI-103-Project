#include "piece.h"
#include "board.h"

using namespace std;

//Piece Stuff
Piece::Piece(bool isWhite) {
    isWhite_ = isWhite;
}

Piece::~Piece() {

}

//Pawn Stuff
Pawn::Pawn(bool isWhite) : Piece(isWhite) {
    hasMoved_ = false;
}

string Pawn::getSymbol() const {
    if (isWhite_) {
        return "♙";
    } else {
        return "♟";
    }
}

bool Pawn::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) {
    //Gets direction of pawn movement so I don't have to rewrite it all for each color
    int direction;
    if (isWhite_) {
        direction = 1;
    } else {
        direction = -1;
    }

    //Check that bounds are good
    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
        return false;
    }

    //Keep a pointer to whatever piece is located at the end point
    Piece* capturedPiece = board->getPiece(eRow, eCol);

    //Handle first pawn move double space
    if (!hasMoved_ && eRow == sRow + 2 * direction && sCol == eCol && capturedPiece == nullptr && board->getPiece(eRow - direction, eCol) == nullptr) {
        hasMoved_ = true;
        return true;
    } //Handle normal pawn move
    else if (eRow == sRow + direction && sCol == eCol && capturedPiece == nullptr) {
        hasMoved_ = true;
        return true;
    } //Handle taking a piece
    else if (eRow == sRow + direction && (eCol == sCol + 1 || eCol == sCol - 1) && capturedPiece != nullptr) {
        if (capturedPiece->isWhite() != isWhite_) {
            hasMoved_ = true;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//Rook Stuff
Rook::Rook(bool isWhite_) : Piece(isWhite) {}

string Rook::getSymbol() const {
    if (isWhite_) {
        return "♖";
    } else {
        return "♜";
    }
}

bool Rook::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const {

}

//Knight Stuff
Knight::Knight(bool isWhite_) : Piece(isWhite) {}

string Knight::getSymbol() const {
    if (isWhite_) {
        return "♘";
    } else {
        return "♞";
    }
}

bool Knight::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const {

}

//Bishop Stuff
Bishop::Bishop(bool isWhite_) : Piece(isWhite) {}

string Bishop::getSymbol() const {
    if (isWhite_) {
        return "♗";
    } else {
        return "♝";
    }
}

bool Bishop::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const {

}

//Queen Stuff
Queen::Queen(bool isWhite_) : Piece(isWhite) {}

string Queen::getSymbol() const {
    if (isWhite_) {
        return "♕";
    } else {
        return "♛";
    }
}

bool Queen::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const {

}

//King Stuff
King::King(bool isWhite_) : Piece(isWhite) {}

string King::getSymbol() const {
    if (isWhite_) {
        return "♔";
    } else {
        return "♚";
    }
}

bool King::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) const {

}
