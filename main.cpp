#include <iostream>
#include <limits>
#include "board.h"
#ifdef _WIN32
#include <windows.h>
#include <ctime>
#endif
#include "enemyAi.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    //Game Variables
    srand(time(0));
    Board* board = new Board();
    enemyAi bot;
    bool playing = true;
    bool whiteTurn = true;
    char sCol;
    int sRow;
    char eCol;
    int eRow;
    char playagain;
    char mode;


    
    //Opening
    board->printBoard();

    cout << "Time for some chess! Choose your Mode: " << endl;
    cout << "(1) 1v1" << endl;
    cout << "(2) You Vs AI" << endl;
    cin >> mode;
    cout << "Make sure to enter pieces and targets as Coloum by Row (letter-number)!" << endl;
    //Main Game Loop
    while (playing) {
        //White Turn Loop
        while (whiteTurn) {
            cout << "White's Move: ";
            if (!(cin >> sCol >> sRow >> eCol >> eRow)) {
                cout << "Invalid input format! Use: a2 a4" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
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
            if(mode == '2'){
                cout << "Black's Turn (Bot)" << endl;
                playing = bot.randomMove(board);

                if(playing){
                    whiteTurn = true;
                    board->printBoard();
                    if(!board->isWhiteKingAlive()) {
                        playing = false;
                        cout << "Bot Wins!" << endl;
                    }
                } else {
                    cout << "White Wins!" << endl;
                }

            } else {
                cout << "Black's Move: ";
                if (!(cin >> sCol >> sRow >> eCol >> eRow)) {
                    cout << "Invalid input format! Use: a7 a5" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
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
        }
        if (!playing) {
            cout << "Want to play again (y/n)" << endl;
            cin >> playagain;
            if (playagain == 'y') {
                playing = true;
                whiteTurn = true;
                board->resetBoard();
                board->printBoard();
                cout << "Time for some chess! Choose your Mode: " << endl;
                cout << "(1) 1v1" << endl;
                cout << "(2) You Vs AI" << endl;
                cin >> mode;
                cout << "Time for some chess! Make sure to enter pieces and targets as Coloum by Row (letter-number)!" << endl;
            } else {
                cout << "Okay bye!" << endl;
            }
        }
    }



    delete board;
    return 0;
}