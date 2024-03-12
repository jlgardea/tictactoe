#ifndef BOARD_H
#define BOARD_H

const int BOARD_SIZE = 3;

class Board{
    char** board;

    public:
        Board();
        ~Board();
        void initializeBoard();
        char getSpot(int row, int col);       
        void setSpot(char mark, int row, int col);
        int getRow(int selection);
        int getColumn(int selection);
        bool isValidMove(int row, int col);
        void placeMove(char mark, int row, int col);
        bool checkWinner(char mark);
        bool isATieGame();
        void printBoard();
};

#endif

