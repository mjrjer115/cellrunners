#include "player.h"
using namespace std;
player::player(){
    this -> hitpoints = 3;
    this -> meter = 1;
};

player::player(int hp, int m)
{
    this -> hitpoints = hp;
    this -> meter = m;
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

player player::operator=(player A)
{
    this -> hitpoints = A.hitpoints;
    this -> meter = A.meter;
    return *this;
};
