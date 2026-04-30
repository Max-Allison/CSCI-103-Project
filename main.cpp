#include <iostream>
#include "board.h"

using namespace std;

int main() {
    //Game Variables
    Board* board = new Board();
    bool playing = true;
    bool whiteTurn = true;
    char sCol;
    int sRow;
    char eCol;
    int eRow;
    char playagain;


    
    //Opening
    board->printBoard();
    cout << "Time for some chess! Make sure to enter pieces and targets as Coloum by Row (letter-number)!" << endl;
    //Main Game Loop
    while (playing) {
        //White Turn Loop
        while (whiteTurn) {
            cout << "White's Move: ";
            cin >> sCol >> sRow >> eCol >> eRow;
            if (board->movePiece(sRow - 1, sCol - 'a', eRow - 1, eCol - 'a')) {
                whiteTurn = false;
                board->printBoard();
                if (!board->isBlackKingAlive()) {
                    playing = false;
                    cout << "White Wins!" << endl;
                }
            } else {
                cout << "Hey that's an invalid move! Try again!" << endl;
            }
        }
        //Black Turn Loop
        while (!whiteTurn && playing) {
            cout << "Black's Move: ";
            cin >> sCol >> sRow >> eCol >> eRow;
            if (board->movePiece(sRow - 1, sCol - 'a', eRow - 1, eCol - 'a')) {
                whiteTurn = true;
                board->printBoard();
                if (!board->isWhiteKingAlive()) {
                    playing = false;
                    cout << "Black Wins!" << endl;
                }
            } else {
                cout << "Hey that's an invalid move! Try again!" << endl;
            }
        }
        if (!playing) {
            cout << "Want to play again (y/n)" << endl;
            cin >> playagain;
            if (playagain == 'y') {
                playing = true;
                whiteTurn = true;
                board->resetBoard();
                board->printBoard();
                cout << "Time for some chess! Make sure to enter pieces and targets as Coloum by Row (letter-number)!" << endl;
            } else {
                cout << "Okay bye!" << endl;
            }
        }
    }



    return 0;
}