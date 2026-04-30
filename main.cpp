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


    
    //Opening
    board->printBoard();
    cout << "Time for some chess! Make sure to enter pieces and targets as Coloum by Row (letter-number)!" << endl;
    //Main Game Loop
    while (playing) {
        //White Turn Loop
        while (whiteTurn) {
            cout << "White's Move: ";
            cin >> sCol >> sRow >> eCol >> eRow;
            if (board->movePiece(sRow, sCol, eRow, eCol)) {
                whiteTurn = false;
            } else {
                cout << "Hey that's an invalid move! Try again!";
            }
        }
        //Black Turn Loop
        while (!whiteTurn) {
            cout << "Black's Move: ";
            cin >> sCol >> sRow >> eCol >> eRow;
            if (board->movePiece(sRow, sCol, eRow, eCol)) {
                whiteTurn = true;
            } else {
                cout << "Hey that's an invalid move! Try again!";
            }
        }
    }

    return 0;
}