#include <iostream>
#include "player.h"
#include "game.h"
using namespace std;



enum {CHARGE, ATTACK, BLOCK, SPECIAL};

game::game(player A,player B)
{
    playerA = A;
    playerB = B;
};

void game::duel(int moveA, int moveB)
    {
        if(moveB == CHARGE)
            this -> playerB.chargeGain();
        if(moveA == CHARGE)
        {
            this -> playerA.chargeGain();

            if(moveB == SPECIAL)
                {
                    this -> playerA.healthLoss(2);
                    this -> playerB.chargeLoss(3);
                }
            if(moveB == ATTACK)
                {
                    this -> playerA.healthLoss();
                    this -> playerB.chargeLoss();
                }
        }

        else if(moveA == ATTACK)
        {
            this -> playerA.chargeLoss();

            if(moveB == ATTACK)
            {
                this -> playerA.healthLoss();
                this -> playerB.healthLoss();
                this -> playerB.chargeLoss();
            }

            else if(moveB == BLOCK)
            this -> playerB.chargeGain();

            else if(moveB == SPECIAL)
            {
                this -> playerB.healthLoss();
                this -> playerB.chargeLoss(3);
            }
            else this -> playerB.healthLoss();
        }

        else if(moveA == BLOCK)
        {
            if(moveB == ATTACK)
            {
                this -> playerA.chargeGain();
                this -> playerB.chargeLoss();
            }
            else if (moveB == SPECIAL)
            {
                this -> playerA.healthLoss();
                this -> playerB.chargeLoss(3);
            }
        }
        else if(moveA == SPECIAL)
        {
            this -> playerA.chargeLoss(3);

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
                this -> playerB.chargeLoss(3);
            }
            else this -> playerB.healthLoss(2);
        }
    }

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
            if(A.getMeter() > 2) return SPECIAL; //will change the number 2 to player.maxMeter and write it
            else cout << "You don't have enough meter." << endl;
        }
        else cout << "Bad input." << endl;
    }
}


void game::run()
{
    int moveA, moveB;
    int ROUND = 1;
    string moves[4]={"Charge","Attack","Block","Special"};
    cout << "Welcome!" << endl << endl;
    cout << "c - Charge: This action gives you one meter." << endl;
    cout << "a - Attack: This action consumes a meter to try and damage the opponent." << endl;
    cout << "b - Block: This action blocks attacks and gives you one meter on successful blocks, but..." << endl;
    cout << "s - Special: This action breaks blocks, but can be countered by an attack and costs 3 meter." << endl << endl;
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
        duel(moveA,moveB);
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
