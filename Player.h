#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
    private:
        string name;
        char mark;
    public:
        Player(string name, char mark);
        char getMark();
        string getName();

};
#endif