#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class player
{
    private:
        int hitpoints;
        int meter;
        int randomNumber;
    public:
        player();
        player(int, int);
        void chargeGain(int k = 1);
        void chargeLoss(int i = 1);
        void healthLoss(int hp = 1);
        void giveRandomNumber(int r = 50);
        int getHealth();
        int getMeter();
        int getRandomNumber();
        player operator=(player A);
};

#endif
