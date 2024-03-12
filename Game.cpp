#include "Game.h"
#include <iostream>
#include <utility>
#include <limits>
#include <random>
#include <set>

using namespace std;


Game::Game(){
    board = new Board();
    board->initializeBoard();
}

void Game::playGame(bool playAI){
    bool winner = false;
    int moves = 0;

    string input;
    char mark;
    bool validMark = false;

    cout << "Enter Player's Name: ";
    getline(cin, input);

    while(!validMark){
        cout << "\nWould you like to be X or O?: ";
        cin >> mark;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        
        switch(tolower(mark)){
            case 'x':
                player1 = new Player(input, 'X');
                break;
            case 'o':
                player2 = new Player(input, 'O');
                break;
            default: cout << "Please enter 'X' or 'O'."; continue; 
        }
        validMark = true;
    }

    Player* aiPlayer = nullptr;
    AI* computer = new AI();
    if(playAI){
        string aiName = "AI Steve";
        if(tolower(mark) == 'x'){
            player2 = new Player(aiName, 'O');
            aiPlayer = player2;
            computer->initialize(aiPlayer, player1);
            }
            else{
            player1 = new Player(aiName, 'X');
            aiPlayer = player1;
            computer->initialize(aiPlayer, player2);
            }
    }else{
        cout << "Enter Second Player's Name: ";
        getline(cin, input);
        tolower(mark) == 'x' ? player2 = new Player(input, 'O') : player1 = new Player(input, 'X');
    }

    Player* currentPlayer = player1;              
    int selectedSpot;            
    int row;
    int col;
    while(!winner){
        board->printBoard();
        
        if(currentPlayer == aiPlayer){
            if(moves == 0){
                srand(time(0));
                selectedSpot = rand() % BOARD_SIZE*BOARD_SIZE + 1;
                row = board->getRow(selectedSpot);
                col = board->getColumn(selectedSpot);
                board->placeMove(currentPlayer->getMark(), row, col);
            }
            else{
                selectedSpot = aiTurn(computer, currentPlayer);
            }
            cout << currentPlayer->getName() << " has moved to spot " << selectedSpot + 1 << ".\n";
        }
        else{

            do{
                int selectedSpot = getMoveSelection(currentPlayer);
                row = board->getRow(selectedSpot);
                col = board->getColumn(selectedSpot);

                if(!board->isValidMove(row, col)){
                    cout << "The move has already been chosen please pick again.\n";
                }
            }while(!board->isValidMove(row, col));

            board->placeMove(currentPlayer->getMark(), row, col);
            
            
        }
        winner = board->checkWinner(currentPlayer->getMark());
        moves++;

        if(winner || moves > 8){break;}
        else{currentPlayer = (currentPlayer == player1) ? player2 : player1;}

    }

    cout << "\n";
    board->printBoard();

    if(winner){
        cout << "\n" << currentPlayer->getName() << " WINS!!!!!\n";
    }
    else{
        cout << "\nIT WAS A DRAW!\n";
    }
    
}

int Game::getMoveSelection(Player* p){
    int move = 0;
    bool validSelection = false;

    do{
        cout << p->getName() << " enter move: ";    
        cin >> move;

        if(!cin.good()){
            cout << "That is not a valid number." << endl;
            cin.clear();
        }
        else if(move < 1 || move > BOARD_SIZE * BOARD_SIZE){
            cout << "Please select a number from the board." << endl;
        }
        else{
            validSelection = true;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  

    }while(!validSelection);

    return move;
}

int Game::aiTurn(AI* a, Player* ai){
    return a->makeAIMove(board, ai);
}



