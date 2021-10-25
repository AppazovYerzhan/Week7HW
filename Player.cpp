#include "Player.h"

void Player::won(){
    Player::score++; //increment the score
}

const string &Player::getName() const {
    return name;
}

int Player::getScore() const {
    return Player::score;
}

void Player::setName(const string &name) {
    Player::name = name;
}

void Player::setScore(int score) {
    Player::score = score;
}

//constructors
Player::Player(){}

Player::Player(string n) :score{0}, name{n}{}

