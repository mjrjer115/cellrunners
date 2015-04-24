#include "player.h"
using namespace std;

enum{STR,DEF,INL,WIS,SPD};

player::player(){
    this -> hitpoints = 3;
    this -> meter = 1;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=0;
    }
};

player::player(int hp, int m)
{
    this -> hitpoints = hp;
    this -> meter = m;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=0;
    }
};

void player::chargeGain(int k)
{
    if (meter < 5) meter += k;
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
/*
void player::giveRandomNumber(int r)
{
    randomNumber = r;
}

int player::getRandomNumber()
{
    return randomNumber;
}
*/
player player::operator=(player A)
{
    this -> hitpoints = A.hitpoints;
    this -> meter = A.meter;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=A.stats[i];
    }
    return *this;
};

int player::getStat(int index)
{
    return stats[index];
}

void player::setStat(int Stat, int index)   //test
{
    stats[index] = Stat;
//  cout << "Entelligence: " << stats[INL] << endl;
}

bool player::roll(int r, int index)
{
//  cout << "Random Number: " << r << endl;
//  cout << "Intelligence: " << stats[INL] << endl;
    if (r <= 50 + (stats[index] - 1) * 25 && stats[index] != 0)
    {
        // chargeGain();
        return true;
    }
    return false;
}
