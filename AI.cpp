#include "AI.h"
#include <iostream>
#include <vector>

using namespace std;

AI::AI(){aiPlayer = nullptr; humanPlayer = nullptr;}

aiMove AI::getBestMove(Board* board, Player* p){
   
    bool aiWins = board->checkWinner(aiPlayer->getMark());
    bool humanWins = board->checkWinner(humanPlayer->getMark());

    if(aiWins){
        return aiMove(10);
    }
    else if(humanWins){
        return aiMove(-10);
    }
    else if(board->isATieGame()){
        return aiMove(0);
    }

    
    vector<aiMove> moves;
    for(int brow = 0; brow < BOARD_SIZE; brow++){
        for (int index = 0; index < BOARD_SIZE; index++){
            if(board->isValidMove(brow, index)){
                char selection = board->getSpot(brow, index);
                aiMove move;
                move.row = brow;
                move.col = index;
                board->placeMove(p->getMark(), brow, index);
                move.score = ( p == aiPlayer) ? getBestMove(board, humanPlayer).score : getBestMove(board, aiPlayer).score;
                moves.push_back(move);
                board->placeMove(selection, brow, index);
            }

        }
    }

    int bestMove = 0;
    if(p == aiPlayer){
        int bestScore = -INT32_MAX;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i].score > bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    else{
        int bestScore = INT32_MAX;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i].score < bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    
    return moves[bestMove];    
}

void AI::initialize(Player* ai, Player* human){
    aiPlayer = ai;
    humanPlayer = human;
}

int AI::makeAIMove(Board* board, Player* ai){

    aiMove best = getBestMove(board, ai);
    board->placeMove(ai->getMark(), best.row, best.col);

    return (best.row  * BOARD_SIZE) + best.col;
}

    
