#include "player.h"
using namespace std;

enum{STR,DEF,INL,WIS,SPD};

player::player(){
    this -> hitpoints = 3;
    this -> meter = 1;
    for(int i = 0; i < 5; i++)
    {
        stats[i]=0;
    }
};

player::player(int hp, int m)
{
    this -> hitpoints = hp;
    this -> meter = m;
    for(int i = 0; i < 5; i++)
    {
        stats[i]=0;
    }
};

void player::chargeGain(int k)
{
    if (meter < 3) meter += k;  //add maxMeter
};

void player::chargeLoss(int i)
{
    if (meter > 0) meter -= i;
};

void player::healthLoss(int hp)
{
    hitpoints -= hp;
};

int player::getHealth()
{
    return hitpoints;
};

int player::getMeter()
{
    return meter;
};

void player::giveRandomNumber(int r)
{
    randomNumber = r;
}

int player::getRandomNumber()
{
    return randomNumber;
}

player player::operator=(player A)
{
    this -> hitpoints = A.hitpoints;
    this -> meter = A.meter;
    return *this;
};
