#ifndef WEEK7HW_GAME_H
#define WEEK7HW_GAME_H
#include "Player.h"
#include "string"
#include <iostream>
#include <cstdlib>
#include "ctime"

class Environment {
    typedef struct{
        int *row;
    }List;
private:
    char board[9];
    int emptyIndex[9];
    int gameOn, againstComputer;
    int emptyCount;
    List list[8];
public:
    Environment();
    void display();
    void botInput();
    void playerInput(Player &player, int whichPlayer);
    void checkWin(Player &p1,Player &p2);
    void play(Player &p1,Player &p2);
    void displayScore(Player &p1, Player &p2);
    void init();
    void onePlayerGame();
    void twoPlayerGame();
    const char *getBoard() const;

    const int *getEmptyIndex() const;

    int getGameOn() const;

    void setGameOn(int gameOn);

    int getAgainstComputer() const;

    void setAgainstComputer(int againstComputer);

    int getEmptyCount() const;

    void setEmptyCount(int emptyCount);

    const List *getlist() const;
};


#endif //WEEK7HW_GAME_H
