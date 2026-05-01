#include "enemyAi.h"
#include <iostream>
using namespace std;

enemyAi::enemyAi() {
    
}

enemyAi::~enemyAi() {

}

bool enemyAi::randomMove(Board* board) {
    validEnemyPieces.clear();
    vector<pieceLocation> holdLegalMoves;
    int randomPiece = 0;
    int randomLocation = 0;

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            Piece* checkingThisPiece = board->getPiece(r, c);
            if(checkingThisPiece != nullptr && checkingThisPiece->isWhite() != true){
                validEnemyPieces.push_back(pieceLocation(r,c));
            }
        }
    }

    while(holdLegalMoves.empty()){
        randomPiece = rand() % validEnemyPieces.size();
        holdLegalMoves = getVectorOfLegalMoves(validEnemyPieces[randomPiece], board);

        if(holdLegalMoves.empty()){
            validEnemyPieces.erase(validEnemyPieces.begin() + randomPiece);
        }

        if(validEnemyPieces.empty()){
            cout << "Wow, you beat the bot!" << endl;
            return false;
        }
    }

    randomLocation = rand() % holdLegalMoves.size();

    board->movePiece(validEnemyPieces[randomPiece].rowLoc, validEnemyPieces[randomPiece].colLoc,
         holdLegalMoves[randomLocation].rowLoc, holdLegalMoves[randomLocation].colLoc);

    return true;
}

vector<pieceLocation> enemyAi::getVectorOfLegalMoves(pieceLocation currentLoc, Board* board){
    int x = currentLoc.rowLoc;
    int y = currentLoc.colLoc;
    vector<pieceLocation> validMoves;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if((board->getPiece(x, y))->getMove(board, x, y, r, c)){
                validMoves.push_back(pieceLocation(r,c));
            }
        }
    }

    return validMoves;
}