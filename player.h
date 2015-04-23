#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

const int NUM_STATS = 5;

class player
{
    private:
        int hitpoints;
        int meter;
//        int randomNumber;
        int stats[NUM_STATS];
    public:
        player();
        player(int, int);
        void chargeGain(int k = 1);
        void chargeLoss(int i = 1);
        void healthLoss(int hp = 1);
        bool roll(int r, int index);
//        void giveRandomNumber(int r = 50);
        void setIntelligence(int x = 0);    // test
        int getHealth();
        int getMeter();
//        int getRandomNumber();
        int getStat(int index);
        player operator=(player A);
};

#endif
