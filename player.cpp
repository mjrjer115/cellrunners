#include "player.h"
#include <ctime>
#include <cstdlib>
using namespace std;

//enumerate stats
enum{STR,DEF,INL,WIS,SPD};
//enumerate actions
enum{CHARGE, ATTACK, BLOCK, SPECIAL, STUNNED};



// constructor with empty arguments; automatically sets hitpoints equal to 3, meter to 3, and all stats to 0
player::player(){
    this -> hitpoints = 3;
    this -> meter = 3;
    this -> character=0;
    this -> hitstun = 0;
    this -> token = 0;
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
    this -> character = 0; // change once character select is implemented
    this -> hitstun = 0;
    this -> token = 0;
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i]=0;
    }
}
//set character
void player::setCharacter(int charac)
{
    character=charac;
    switch(this->character)
    {
    case NIL:
        this -> hitpoints = 300;
        this -> meter = 3;
        break;
    case EVE:
        this -> hitpoints = 400;
        this -> meter = 2;
        break;
    case LANCER:
        this -> hitpoints = 400;
        this -> meter = 2;
        break;
    case SKELTO:
        this -> hitpoints = 500;
        this -> meter = 0;
        break;
    default:
        cout << "We broke it (setChar)" << endl;
    }
}


// causes the player to gain charge as long as it is < 0
// 5-8-15: max meter is different per character and can be changed here
void player::chargeGain(int k)
{
    //if (meter < 5) meter += k;
    switch(this->character)
    {
    case NIL:
        if (meter < 6) meter += k;
        break;
    case EVE:
        if (meter < 4) meter += k;
        break;
    case LANCER:
        if (meter < 6) meter += k;
        break;
    case SKELTO:
        if (meter < 5) meter += k;
        break;
    default:
        cout << "We broke it worse (chargeGain)" << endl;
    }
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


//causes the player to gain health... although we don't really use this
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

// checks if the player has enough meter for the action
bool player::checkMeter(int act)
{
    switch(this->character)
    {
    case NIL:
        if(meter > 0 && act == ATTACK)
            return true;
        else if (meter > 1 && act == SPECIAL)
            return true;
        else return false;
        break;
    case EVE:
        if(meter > 0 && act == ATTACK)
            return true;
        else if (meter > 1 && act == SPECIAL)
            return true;
        else return false;
        break;
    case LANCER:
        if(meter > 1 && act == ATTACK)
            return true;
        else if (meter > 2 && act == SPECIAL)
            return true;
        else return false;
        break;
    case SKELTO:
        if(meter > 0 && act == ATTACK)
            return true;
        else if (meter > 4 && act == SPECIAL)
            return true;
        else return false;
        break;
    default:
        cout << "We fucked up (checkMeter)" << endl;
        return true;
    }
}

// associate attacks with characters
void player::attack(player& enem, int move)
{
    switch(this->character)
    {
    case NIL:
        if(move == BLOCK)
        {
            this -> chargeLoss();
            enem.chargeGain();
        }
        else
        {
            this -> chargeLoss();
            if (meter < 1) enem.healthLoss(150+(rand()%100));
            else enem.healthLoss(75+(rand()%50));
        }
        break;
    case EVE:
        if(move == BLOCK)
        {
            this -> chargeLoss();
            enem.chargeGain();
        }
        else
        {
            this -> chargeLoss();
            if (meter < 1) enem.healthLoss(150+(rand()%100));
            else enem.healthLoss(80+(rand()%40));
        }
        break;
    case LANCER:
        if(move == BLOCK)
        {
            this -> chargeLoss(2);
            enem.chargeGain();
            stun(1);
        }
        else
        {
            this -> chargeLoss(2);
            if (meter < 1) enem.healthLoss(250+rand()%100);
            else enem.healthLoss(150+(rand()%100));
        }
        break;
    case SKELTO:
        if(move == BLOCK)
        {
            this -> chargeLoss();
            enem.chargeGain();
            if(token == 1) enem.healthLoss(50+rand()%100);
        }
        else
        {
            cout << "TOKEN = " << token << endl;
            if(token == 0) chargeGain();
            else if(token == 1)
                {
                    enem.healthLoss(200+rand()%50);
                    chargeLoss();
                }
        }
        break;
    default:
        cout << "We broke it hard (attack)" << endl;
    }
}

// associate specials with characters
void player::special(player& enem, int move)
{
    switch(this->character)
    {
    case NIL:
        RexRim(enem,move);
        break;
    case EVE:
        ShieldBash(enem,move);
        break;
    case LANCER:
        Whirlwind(enem,move);
        break;
    case SKELTO:
        Awakening(enem,move);
        break;
    default:
        cout<<"We broked it (special)"<<endl;
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
    this -> character = A.character;
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

// stun prevents a player from performing an action
void player::stun(int turnsStunned)
{
    hitstun = turnsStunned + 1;
}

// unStun decrements the hitstun counter after every round
void player::unStun()
{
    if(hitstun > 0)
        hitstun--;
}

// returns the rounds stunned
int player::getStun()
{
    return hitstun;
}

// proceeds with an action for a player
// "move" refers to the player's move -- not the enemies move
// this is normally used only when the other player is stunned
void player::action(player& enem, int move)
{
    if(move == ATTACK)  //if implementing attack function, don't forget to put it here
    {
        attack(enem, STUNNED);
    }
    else if(move == CHARGE)
    {
        this->chargeGain();
    }
    else if (move == SPECIAL)
    {
        special(enem,-1); //negative 1 must be put in as a dummy input: see specials region of why we put move = -1
    }
    else{}
}

//______________________________________________________________________________
//SPECIALS BEGIN HERE: BEWARE
//the integer "move" refers to the enemies move in this region

//RexRim is the vanilla special
void player::RexRim(player& enem, int move){
    this->chargeLoss(2);
    if(move == ATTACK)
        {
            enem.attack(*this, SPECIAL);
        }
    else if(move == BLOCK)
        {
            enem.healthLoss(100);
        }
    else if(move == CHARGE)
        {
            enem.healthLoss(200);
            enem.chargeLoss();
            enem.stun(1);
        }
    else
        {
            enem.healthLoss(200);
            enem.stun(1);
        }
}

//ShieldBash is Eve's special
void player::ShieldBash(player& enem, int move){
    this->chargeLoss(2);
    if(move == ATTACK)
    {
        enem.attack(*this, SPECIAL);
    }
    else if(move == BLOCK)
    {
        enem.healthLoss(100);
        enem.stun(1);
    }
    else if(move == CHARGE)
    {
        enem.healthLoss(100);
        enem.chargeLoss();
        enem.stun(2);
    }
    else
        enem.healthLoss(100);
}

void player::Whirlwind(player& enem, int move){
    this->chargeLoss(3);
    if(move == ATTACK)
    {
        enem.attack(*this,SPECIAL);
        stun(1);
    }
    else if(move == BLOCK)
    {
        enem.healthLoss(300);
        enem.stun(1);
    }
    else if(move == CHARGE)
    {
        enem.healthLoss(300);
        enem.chargeLoss();
        enem.stun(1);
    }
    else
        enem.healthLoss(300);
}

void player::Awakening(player& enem, int move)
{
    this->chargeLoss(3);
    this->healthGain(200);
    token = 1;
}
