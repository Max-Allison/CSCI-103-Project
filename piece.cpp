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
    if (!isWhite_) {
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
Rook::Rook(bool isWhite) : Piece(isWhite) {}

string Rook::getSymbol() const {
    if (!isWhite_) {
        return "♖";
    } else {
        return "♜";
    }
}

bool Rook::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) {
    //Check that bounds are good
    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
        return false;
    }

    //Keep a pointer to whatever piece is located at the end point
    Piece* capturedPiece = board->getPiece(eRow, eCol);

    //First check to see what direction
    //Going Up
    if (eRow > sRow && eCol == sCol) {
        for (int i = sRow + 1; i < eRow; i++) {
            if (board->getPiece(i, sCol) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Going Down
    else if (eRow < sRow && eCol == sCol) {
        for (int i = sRow - 1; i > eRow; i--) {
            if (board->getPiece(i, sCol) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Going Right
    else if (eRow == sRow && eCol > sCol) {
        for (int i = sCol + 1; i < eCol; i++) {
            if (board->getPiece(sRow, i) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Going Left
    else if (eRow == sRow && eCol < sCol) {
        for (int i = sCol - 1; i > eCol; i--) {
            if (board->getPiece(sRow, i) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } else {
        return false;
    }
}

//Knight Stuff
Knight::Knight(bool isWhite) : Piece(isWhite) {}

string Knight::getSymbol() const {
    if (!isWhite_) {
        return "♘";
    } else {
        return "♞";
    }
}

bool Knight::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) {
    //Check that bounds are good
    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
        return false;
    }

    //Keep a pointer to whatever piece is located at the end point
    Piece* capturedPiece = board->getPiece(eRow, eCol);

    //Check directions
    //Up Left & Right
    if ((eRow - sRow == 2 && (eCol - sCol == 1 || eCol - sCol == -1)) 
        //Down Left & Right
        || (eRow - sRow == -2 && (eCol - sCol == 1 || eCol - sCol == -1))
        //Right Up & Down 
        || (eCol - sCol == 2 && (eRow - sRow == 1 || eRow - sRow == -1))
        //Left Up & Down 
        || (eCol - sCol == -2 && (eRow - sRow == 1 || eRow - sRow == -1)) ) {
            if (capturedPiece != nullptr) {
                if (capturedPiece->isWhite() != isWhite_) {
                    return true;
                } else {return false;}
            } else {return true;}
        } else {
            return false;
        }
}

//Bishop Stuff
Bishop::Bishop(bool isWhite) : Piece(isWhite) {}

string Bishop::getSymbol() const {
    if (!isWhite_) {
        return "♗";
    } else {
        return "♝";
    }
}

bool Bishop::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) {
    //Check that bounds are good
    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
        return false;
    }

    //Keep a pointer to whatever piece is located at the end point
    Piece* capturedPiece = board->getPiece(eRow, eCol);

    //Check for which direction
    //Up Right
    if (eRow > sRow && eCol > sCol && eRow - sRow == eCol - sCol) {
        int j = sCol + 1;
        for (int i = sRow + 1; i < eRow; i++) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j++;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } //Up Left
    else if (eRow > sRow && eCol < sCol && eRow - sRow == sCol - eCol) {
        int j = sCol - 1;
        for (int i = sRow + 1; i < eRow; i++) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j--;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } //Down Right
    else if (eRow < sRow && eCol > sCol && sRow - eRow == eCol - sCol) {
        int j = sCol + 1;
        for (int i = sRow - 1; i > eRow; i--) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j++;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } //Down Left
    else if (eRow < sRow && eCol < sCol && sRow - eRow == sCol - eCol) {
        int j = sCol - 1;
        for (int i = sRow - 1; i > eRow; i--) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j--;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

//Queen Stuff
Queen::Queen(bool isWhite) : Piece(isWhite) {}

string Queen::getSymbol() const {
    if (!isWhite_) {
        return "♕";
    } else {
        return "♛";
    }
}

bool Queen::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) {
    //Check that bounds are good
    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
        return false;
    }

    //Keep a pointer to whatever piece is located at the end point
    Piece* capturedPiece = board->getPiece(eRow, eCol);

    //Check for which direction (just copies rook and bishop movement)
    //Going Up
    if (eRow > sRow && eCol == sCol) {
        for (int i = sRow + 1; i < eRow; i++) {
            if (board->getPiece(i, sCol) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Going Down
    else if (eRow < sRow && eCol == sCol) {
        for (int i = sRow - 1; i > eRow; i--) {
            if (board->getPiece(i, sCol) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Going Right
    else if (eRow == sRow && eCol > sCol) {
        for (int i = sCol + 1; i < eCol; i++) {
            if (board->getPiece(sRow, i) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Going Left
    else if (eRow == sRow && eCol < sCol) {
        for (int i = sCol - 1; i > eCol; i--) {
            if (board->getPiece(sRow, i) != nullptr) {
                return false;
            } 
        } if (capturedPiece != nullptr) { 
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {
            return true;
        }
    } //Up Right 
    else if (eRow > sRow && eCol > sCol && eRow - sRow == eCol - sCol) {
        int j = sCol + 1;
        for (int i = sRow + 1; i < eRow; i++) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j++;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } //Up Left
    else if (eRow > sRow && eCol < sCol && eRow - sRow == sCol - eCol) {
        int j = sCol - 1;
        for (int i = sRow + 1; i < eRow; i++) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j--;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } //Down Right
    else if (eRow < sRow && eCol > sCol && sRow - eRow == eCol - sCol) {
        int j = sCol + 1;
        for (int i = sRow - 1; i > eRow; i--) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j++;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } //Down Left
    else if (eRow < sRow && eCol < sCol && sRow - eRow == sCol - eCol) {
        int j = sCol - 1;
        for (int i = sRow - 1; i > eRow; i--) {
            if (board->getPiece(i, j) != nullptr) {
                return false;
            }
            j--;
        } if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

//King Stuff
King::King(bool isWhite) : Piece(isWhite) {}

string King::getSymbol() const {
    if (!isWhite_) {
        return "♔";
    } else {
        return "♚";
    }
}

bool King::getMove(Board* board, int sRow, int sCol, int eRow, int eCol) {
    //Check that bounds are good
    if (eRow > 7 || eRow < 0 || eCol > 7 || eCol < 0) {
        return false;
    }

    //Keep a pointer to whatever piece is located at the end point
    Piece* capturedPiece = board->getPiece(eRow, eCol);

    //Check to make sure not same square as king
    if (eRow == sRow && eCol == sCol) {
        return false;
    }

    //Check move is to adjacent square
    if (eRow - sRow <= 1 && eRow - sRow >= -1 && eCol - sCol <= 1 && eCol - sCol >= -1) {
        if (capturedPiece != nullptr) {
            if (capturedPiece->isWhite() != isWhite_) {
                return true;
            } else {return false;}
        } else {return true;}
    } else {
        return false;
    }
}
