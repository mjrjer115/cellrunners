#include "player.h"
using namespace std;


//enumerate stats
enum{STR,DEF,INL,WIS,SPD};
enum {CHARGE, ATTACK, BLOCK, SPECIAL};



// constructor with empty arguments; automatically sets hitpoints equal to 3, meter to 1, and all stats to 0
player::player(){
    this -> hitpoints = 3;
    this -> meter = 1;
    this -> character=1;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=0;
    }
};



// constructor for player, hp is the amount of hitpoints the player will have and m is the meter we will give them
// stats are automatically set to zero when the player is made
player::player(int hp, int m)
{
    this -> hitpoints = hp;
    this -> meter = m;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=0;
    }
}
//set character
void player::setCharacter(int charac)
{
    character=charac;
}


// causes the player to gain charge as long as it is < 0
void player::chargeGain(int k)
{
    if (meter < 5) meter += k;
}



// causes the player to lose charge as long as it is > 0
void player::chargeLoss(int i)
{
    if (meter > 0) meter -= i;
}



// causes the player to lose health
void player::healthLoss(int hp)
{
    hitpoints -= hp;
}



void player::healthGain(int hp)
{
    hitpoints += hp;
}



// returns health of player
int player::getHealth()
{
    return hitpoints;
}



// returns meter of player
int player::getMeter()
{
    return meter;
}

//associate specials with characters
void player::special(player& enem, int move){
    switch(this->character){
        case 1:
            RexRim(enem,move);
            break;
        default:
            cout<<"We broke it"<<endl;
    }

}



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




// sets the player's properties equal (hitpoints, meter and stats)
player player::operator=(player A)
{
    this -> hitpoints = A.hitpoints;
    this -> meter = A.meter;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=A.stats[i];
    }
    return *this;
}




// returns a stat based on the stat in question
int player::getStat(int index)
{
    return stats[index];
}



// a temporary function that sets a certain stat for the current player
// index is the stat in question
// Stat is the number that we want to set it to
void player::setStat(int Stat, int index)   //test
{
    stats[index] = Stat;
//  cout << "Entelligence: " << stats[INL] << endl;
}



// roll takes random number,index
// index is the part of the stat
// returns a true if the roll succeeds, else returns false
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



//______________________________________________________________________________
//SPECIALS BEGIN HERE: BEWARE

void player::RexRim(player& enem, int move){
    this->chargeLoss(2);
    if(move = ATTACK)
        this->healthLoss(1);
    else if(move = BLOCK)
        enem.healthLoss(1);
    else
        enem.healthLoss(2);

}
