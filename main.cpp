#include <iostream>
#include "Game.h"

int main() {
    int ch;

    while(true){
        cout<< "      ----------MAIN MENU----------" << endl;
        cout << "\t 1. Single Player" <<endl;
        cout << "\t 2. Multiplayer" <<endl;
        cout << "\t 3. To exit " <<endl;
        cout <<"      ------------------------" << endl;
        cin >> ch;
        switch(ch){
            case 1:{
                Game *game = new Game;
                game->init();
                game->onePlayerGame();
            }
                break;
            case 2:{
                Game *game = new Game;
                game->init();
                game->twoPlayerGame();
            }
                break;
            case 3:
                return 0;
            default:
                cout << "OOPs Invalid Option! TRY AGAIN";
        }

    }
    return 0;
}
