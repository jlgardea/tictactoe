#include "Player.h"

using namespace std;

Player::Player(string name, char mark):name(name), mark(mark){}

char Player::getMark(){
    return this->mark;
}

string Player::getName(){
    return this->name;
}