#include <string>

#include "piece.h"
#include "board.h"
#include <vector>
#include <cstdlib>
using namespace std;

struct pieceLocation{
    int rowLoc;
    int colLoc;
    pieceLocation(int rl, int cl){
        rowLoc = rl;
        colLoc = cl;
    }
};

class enemyAi{
    public:

    enemyAi();

    ~enemyAi();

    bool randomMove(Board* board);

    vector<pieceLocation> getVectorOfLegalMoves(pieceLocation currentLoc, Board* board);

    protected:
    vector<pieceLocation> validEnemyPieces;

    


};