#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "AI.h"

#include <set>

using namespace std;

class Game{
    private:
        Board* board;
        Player* player1;
        Player* player2;

        int getMoveSelection(Player* p);
        int aiTurn(AI* a, Player* ai);
    public:
        Game();
        void playGame(bool playAI);
};
#endif