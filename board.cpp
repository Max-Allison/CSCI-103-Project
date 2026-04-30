
#include "board.h"
#include <iostream>

using namespace std;

// Set everything to empty, then place pieces
Board::Board() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            board_[r][c] = nullptr;
        }
    }
    resetBoard();
}

// Clean up all allocated pieces
Board::~Board() {
    clearBoard();
}

// Delete every piece on the board
void Board::clearBoard() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            delete board_[r][c];
            board_[r][c] = nullptr;
        }
    }
}

// Put all pieces back in starting positions
void Board::resetBoard() {
    clearBoard();

    // White pieces (bottom)
    board_[0][0] = new Rook(true);
    board_[0][1] = new Knight(true);
    board_[0][2] = new Bishop(true);
    board_[0][3] = new Queen(true);
    board_[0][4] = new King(true);
    board_[0][5] = new Bishop(true);
    board_[0][6] = new Knight(true);
    board_[0][7] = new Rook(true);

    // White pawns
    for (int c = 0; c < 8; c++) {
        board_[1][c] = new Pawn(true);
    }

    // Black pieces (top)
    board_[7][0] = new Rook(false);
    board_[7][1] = new Knight(false);
    board_[7][2] = new Bishop(false);
    board_[7][3] = new Queen(false);
    board_[7][4] = new King(false);
    board_[7][5] = new Bishop(false);
    board_[7][6] = new Knight(false);
    board_[7][7] = new Rook(false);

    // Black pawns
    for (int c = 0; c < 8; c++) {
        board_[6][c] = new Pawn(false);
    }
    isBlackKingAlive_ = true;
    isWhiteKingAlive_ = true;
}

// Check if position is valid
bool Board::inBounds(int row, int col) const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

// Return piece at location (or nullptr)
Piece* Board::getPiece(int row, int col) const {
    if (!inBounds(row, col)) return nullptr;
    return board_[row][col];
}

// Try to move a piece
bool Board::movePiece(int sRow, int sCol, int eRow, int eCol) {

    // Make sure positions are on the board
    if (!inBounds(sRow, sCol) || !inBounds(eRow, eCol)) {
        return false;
    }

    Piece* moving = board_[sRow][sCol];

    // No piece selected
    if (moving == nullptr) {
        return false;
    }

    Piece* target = board_[eRow][eCol];

    // Can't capture your own piece
    if (target != nullptr && target->isWhite() == moving->isWhite()) {
        return false;
    }

    // Let the piece decide if move is valid
    if (!moving->getMove(this, sRow, sCol, eRow, eCol)) {
        return false;
    }

    //Check if captured piece is a king
    if (board_[eRow][eCol] != nullptr) {
        if (board_[eRow][eCol]->getSymbol() == "♔") {
            isBlackKingAlive_ = false;
        } else if (board_[eRow][eCol]->getSymbol() == "♚") {
            isWhiteKingAlive_ = false;
        }
    }

    // Remove captured piece if there is one
    delete board_[eRow][eCol];

    // Move piece
    board_[eRow][eCol] = moving;
    board_[sRow][sCol] = nullptr;

    return true;
}

// Print board with coordinates and symbols
void Board::printBoard() const {
    cout << endl;
    cout << "  a b c d e f g h" << endl;

    // Print from top (row 7) to bottom (row 0)
    for (int r = 7; r >= 0; r--) {
        cout << r + 1 << " ";

        for (int c = 0; c < 8; c++) {
            if (board_[r][c] == nullptr) {
                cout << ". ";
            } else {
                cout << board_[r][c]->getSymbol() << " ";
            }
        }

        cout << r + 1 << endl;
    }

    cout << "  a b c d e f g h" << endl;
}

bool Board::isBlackKingAlive() const {
    return isBlackKingAlive_;
}

bool Board::isWhiteKingAlive() const {
    return isWhiteKingAlive_;
}
