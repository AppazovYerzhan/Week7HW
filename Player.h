#include <string>
#include "iostream"

using namespace std;

#ifndef WEEK7HW_PLAYER_H
#define WEEK7HW_PLAYER_H


class Player {
private:
    string name;
    int score;
public:
    Player();
    Player(string n);

    void won();

    const string &getName() const;  //Getters
    int getScore() const;

    void setName(const string &name);   //Setters
    void setScore(int score);

};


#endif //WEEK7HW_PLAYER_H