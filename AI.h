#ifndef AI_H
#define AI_H

/* adjusted AI Algorithm from https://youtu.be/CwziaVrM_vc?si=qmuwIFYUoYVBZveP */

#include "Player.h"
#include "Board.h"

using namespace std;

struct aiMove{
    aiMove(){};
    aiMove(int score): score(score){};
    int row;   
    int col;
    int score;
};

class AI{
    private:
        Player* aiPlayer;
        Player* humanPlayer;
        aiMove getBestMove(Board* board, Player* ai);
    public:
        AI();
        void initialize(Player* ai, Player* human);
        int makeAIMove(Board* board, Player* p);    
};

#endif