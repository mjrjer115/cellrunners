#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

const int NUM_STATS = 5;

class player
{
    private:
        int hitpoints;
        int meter;
        int character;
        int hitstun;
//        int randomNumber;
        int stats[NUM_STATS];
    public:
        player();
        player(int, int);
        void setCharacter(int charac=0);
        void chargeGain(int k = 1);
        void chargeLoss(int i = 1);
        void healthLoss(int hp = 1);
        void healthGain(int hp = 1);
        void special(player& enem, int move);
        void action(player& enem, int move);
        bool roll(int r, int index);
//        void giveRandomNumber(int r = 50);
        void setStat(int x, int index);
        int getHealth();
        int getMeter();
        void stun(int s = 1);
        int getStun();
        void unStun();
//        int getRandomNumber();
        int getStat(int index);
        player operator=(player A);





        //specials
        void RexRim(player& enem, int move);
        void ShieldBash(player& enem, int move);
};

#endif
