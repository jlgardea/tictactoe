#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;

int main(){
    cout << "LET'S PLAY TIC TAC TOE!\n\n";
    char playing = 'y';
    while(playing == 'y'){
        Game g = Game(); 
        
        char multiPlayer;
        cout << "MultiPlayer Game? (y/n): ";
        cin >> multiPlayer;
        multiPlayer = tolower(multiPlayer);

        if(!cin.good()){
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  

        switch(multiPlayer){
            case 'y':{
                cout << "Two Player Game\n"; 
                g.playGame(false);
                
                break;
                }
            case 'n':{ 
                cout << "Playing with the Computer\n"; 
                g.playGame(true);

                break;
                }

            default: cout << "That choice is not recognized.\n\n"; continue; 
        }
        cout << "\n";
        cout << "Enter 'y' to play again: ";
        cin >> playing;
        playing = tolower(playing);
        cout << "\n";

    }
    
    return 0;
}