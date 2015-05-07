#include <iostream>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "game.h"
using namespace std;


enum {STR, DEF, INL, WIS, SPD};
enum {CHARGE, ATTACK, BLOCK, SPECIAL};

//sets the game up with two players, A and B
game::game(player A,player B)
{
    playerA = A;
    playerB = B;
};

// compares the player's actions, and edits the player's properties accordingly
// prints if any crits occurred
string game::duel(int moveA, int moveB)
    {
        string output = "";

        if(moveB == CHARGE)
        {
            this -> playerB.chargeGain();
            if (playerB.roll(rand()%1000,INL))
            {
                playerB.chargeGain();
                output += "Player 2 obtained an extra charge!\n";
            }
        }
        if(moveA == CHARGE)
        {
            this -> playerA.chargeGain();
            if (playerA.roll(rand()%1000,INL))
            {
                playerA.chargeGain();
                output += "Player 1 obtained an extra charge!\n";
            }
            if(moveB == SPECIAL)
                {
                    this -> playerA.healthLoss(2);
                    this -> playerB.chargeLoss(2);
                    this -> playerA.chargeLoss();
                }
            if(moveB == ATTACK)
                {
                    this -> playerB.chargeLoss();
                    if (playerB.roll(rand()%1000,STR))
                    {
                        output += "Player 2 landed a critical hit!\n";
                        playerA.healthLoss(2);
                    }
                    else if (playerA.roll(rand()%1000,DEF))
                    {
                        output += "Player 1 deflected Player 2's attack!\n";
                    }
                    else playerA.healthLoss();
                }
        }
        else if(moveA == ATTACK)
        {
            this -> playerA.chargeLoss();
            if(moveB == ATTACK)
            {
                this -> playerB.chargeLoss();
                if(playerA.getStat(SPD) > playerB.getStat(SPD))
                {
                    output += "Player 1 is faster than Player 2!\n";
                    playerB.healthLoss();
                }
                else if(playerB.getStat(SPD) > playerA.getStat(SPD))
                {
                    output += "Player 2 is faster than Player 1!\n";
                    playerA.healthLoss();
                }
                else
                {
                    output += "Player 1 and 2 hit each other at the same speed!\n";
                    playerA.healthLoss();
                    playerB.healthLoss();
                }
            }
            else if(moveB == BLOCK)
            {
                this -> playerB.chargeGain();
                if(playerB.roll(rand()%1000,WIS))
                {
                    output += "Player 2 gained two charges on block!\n";
                    playerB.chargeGain();
                }
            }
            else if(moveB == SPECIAL)
            {
                this -> playerB.healthLoss();
                this -> playerB.chargeLoss(2);
            }
            else if(playerA.roll(rand()%1000,STR))
            {
                output += "Player 1 landed a critical hit!\n";
                playerB.healthLoss(2);
            }
            else if(playerB.roll(rand()%1000,DEF))
            {
                output += "Player 2 deflected Player 1's attack!\n";
            }
            else this -> playerB.healthLoss();
        }

        else if(moveA == BLOCK)
        {
            if(moveB == ATTACK)
            {
                this -> playerA.chargeGain();
                this -> playerB.chargeLoss();
                if(playerA.roll(rand()%1000,WIS))
                {
                    output += "Player 1 gained two charges on block!\n";
                    playerA.chargeGain();
                }
            }
            else if (moveB == SPECIAL)
            {
                this -> playerA.healthLoss();
                this -> playerB.chargeLoss(2);
            }
        }
        else if(moveA == SPECIAL)
        {
            this -> playerA.chargeLoss(2);

            if(moveB == ATTACK)
            {
                this -> playerA.healthLoss();
                this -> playerB.chargeLoss();
            }

            else if(moveB == BLOCK)
            {
                this -> playerB.healthLoss();
            }

            else if(moveB == SPECIAL)
            {
                this -> playerA.healthLoss(2);
                this -> playerB.healthLoss(2);
                this -> playerB.chargeLoss(2);
            }
            else
            {
                this -> playerB.healthLoss(2);
                this -> playerB.chargeLoss();
            }
        }
        return output;
    }

// takes input during the game for the player mentioned in the argument
int game::input(player A)
{
    string thong;     //shawn is gay so this is actually input
    while(true)
    {
        cin >> thong;
        if(thong == "c") return CHARGE;
        else if(thong == "a")
        {
            if(A.getMeter() > 0) return ATTACK;
            else cout << "You don't have enough meter." << endl;
        }
        else if(thong == "b") return BLOCK;
        else if(thong == "s")
        {
            if(A.getMeter() > 1) return SPECIAL; //will change the number 2 to player.maxMeter and write it
            else cout << "You don't have enough meter." << endl;
        }
        else cout << "Bad input." << endl;
    }
}

void game::run() // loop until someone dies
{
    srand(time(NULL));
    int moveA, moveB;
    int ROUND = 1;
    string moves[4]={"Charge","Attack","Block","Special"};
    cout << "Welcome!" << endl << endl;
    cout << "c - Charge: This action gives you one meter." << endl;
    cout << "a - Attack: This action consumes a meter to try and damage the opponent." << endl;
    cout << "b - Block: This action blocks attacks and gives you one meter on successful blocks, but..." << endl;
    cout << "s - Special: This action breaks blocks, but can be countered by an attack and costs 2 meter." << endl << endl;
    cout << "Good luck!" << endl << endl;
    cout << "Player 1 health: " << playerA.getHealth() << endl;
    cout << "Player 1 meter:  " << playerA.getMeter() << endl;
    cout << "Player 2 health: " << playerB.getHealth() << endl;
    cout << "Player 2 meter:  " << playerB.getMeter() << endl << endl;
    while(playerA.getHealth() > 0 && playerB.getHealth() > 0)
    {
        cout << "Player 1, act" << endl;
        moveA = input(playerA);
        cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' ;
        cout << "Player 1 health: " << playerA.getHealth() << endl;
        cout << "Player 1 meter:  " << playerA.getMeter() << endl;
        cout << "Player 2 health: " << playerB.getHealth() << endl;
        cout << "Player 2 meter:  " << playerB.getMeter() << endl << endl;
        cout << "Player 2, act" << endl;
        moveB = input(playerB);
        string crit = duel(moveA,moveB);
        cout << endl << crit;

        cout << endl << endl << "OUTCOME OF ROUND " << ROUND << ":" << endl << endl;
        cout << "Player 1 action: " << moves[moveA] << endl;
        cout << "Player 2 action: " << moves[moveB] << endl << endl;

        cout << "Player 1 health: " << playerA.getHealth() << endl;
        cout << "Player 1 meter:  " << playerA.getMeter() << endl;
        cout << "Player 2 health: " << playerB.getHealth() << endl;
        cout << "Player 2 meter:  " << playerB.getMeter() << endl << endl;
        ROUND++;
    }
    if (playerA.getHealth() > 0)
    {
        cout << "Player 1 wins!" << endl;
    }
    else if (playerB.getHealth() > 0)
    {
        cout << "Player 2 wins!" << endl;
    }
    else cout << "What the fuck just happened" << endl;
};
