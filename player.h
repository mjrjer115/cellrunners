#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class player
{
    private:
        int hitpoints;
        int meter;
    public:
        player();
        player(int, int);
        void chargeGain(int k = 1);
        void chargeLoss(int i = 1);
        void healthLoss(int hp = 1);
        int getHealth();
        int getMeter();
        player operator=(player A);
};

#endif
