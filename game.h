#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.h"

class game
{
private:
    player playerA;
    player playerB;
    void duel(int moveA, int moveB);
public:
    game(player A,player B);
    void run();
    int input(player A);
};

#endif
