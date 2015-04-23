#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

class game
{
private:
    player playerA;
    player playerB;
    string duel(int moveA, int moveB);
public:
    game(player A,player B);
    void run();
    int input(player A);
};

#endif
