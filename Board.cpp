#include "Board.h"

#include <iostream>

using namespace std;

Board::Board(){
    board = new char*[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i++){
        board[i] = new char[BOARD_SIZE];
    }
}

Board::~Board(){
    for(int i = 0; i < BOARD_SIZE; i++){
        delete[] board[i];
    }
    delete[] board;
}

void Board::initializeBoard(){
    char space = '1';
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = space++;
        }
    }
}

char Board::getSpot(int row, int col){
    return board[row][col];
}

void Board::setSpot(char mark, int row, int col){
    board[row][col] = mark;
}

int Board::getRow(int spotNumber){
    int row = (spotNumber - 1) / BOARD_SIZE;
    return row;
}

int Board::getColumn(int spotNumber){
    int column = (spotNumber - 1) % BOARD_SIZE;
    return column;
}

bool Board::isValidMove(int row, int col){
    if(isdigit(board[row][col])){
        return true;
    }
    return false;
}

void Board::placeMove(char mark, int row, int col){
    board[row][col] = mark;
}

bool Board::checkWinner(char mark){

    for(int index = 0; index < BOARD_SIZE; index++){
        //check each row
        if(board[index][0] == mark && board[index][1] == mark && board[index][2] == mark){
            return true;
        }
        //check each column
            if(board[0][index] == mark && board[1][index] == mark && board[2][index] == mark){
            return true;
        }

    }
    //check diag
    if(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark){
        return true;
    }
    if(board[2][0] == mark && board[1][1] == mark && board[0][2] == mark){
        return true;
    }
        return false;
}

bool Board::isATieGame(){
    for(int row = 0; row < BOARD_SIZE; ++row){
        for(int index = 0; index < BOARD_SIZE; index++){
            if(isValidMove(row, index)){
                return false;
            }
        }
    }
    return true;
}

void Board::printBoard(){
    cout << '\n';
    for(int row = 0; row < BOARD_SIZE; row++){
        for (int index = 0; index < BOARD_SIZE; index++){
            cout << board[row][index];
            if(index != BOARD_SIZE - 1){
                cout << " | ";
            }
        }
        if(row != BOARD_SIZE - 1){
            cout << "\n---------" << endl;
        }
    }
    cout << endl;
}