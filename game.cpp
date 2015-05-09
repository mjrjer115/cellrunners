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

// 5-8-15: checks if players are stunned, then
// compares the player's actions, and edits the player's properties accordingly
// prints if any crits occurred
string game::duel(int moveA, int moveB)
    {
        string output = "";
        if(playerA.getStun()!=0) // if player 1 is stunned
        {
            playerB.action(playerA,moveB); //let player 2 perform his action
            playerA.unStun(); // decrement stun after each duel
            playerB.unStun();
            return output; //and leave duel
        }
        else if (playerB.getStun()!=0) // if player 2 is stunned
        {
            playerA.action(playerB,moveA); //let player 1 perform his action
            playerA.unStun(); // decrement stun after each duel
            playerB.unStun();
            return output; //and leave duel
        }

        //else, proceed normally

        if(moveB == CHARGE)
        {
            this -> playerB.chargeGain();
        }
        if(moveA == CHARGE)
        {
            this -> playerA.chargeGain();
            if(moveB == SPECIAL)
                playerB.special(playerA,moveA);
            if(moveB == ATTACK)
                {
                    this -> playerB.chargeLoss();
                    playerA.healthLoss();
                }
        }
        else if(moveA == ATTACK)
        {
            this -> playerA.chargeLoss();
            if(moveB == ATTACK)
            {
                this -> playerB.chargeLoss();
                playerA.healthLoss();
                playerB.healthLoss();
            }
            else if(moveB == BLOCK)
            {
                this -> playerB.chargeGain();
            }
            else if(moveB == SPECIAL)
                playerB.special(playerA,moveA);
            else
                this -> playerB.healthLoss();
        }

        else if(moveA == BLOCK)
        {
            if(moveB == ATTACK)
            {
                this -> playerA.chargeGain();
                this -> playerB.chargeLoss();
            }
            else if (moveB == SPECIAL)
                playerB.special(playerA,moveA);
        }
        else if(moveA == SPECIAL)
        {
            playerA.special(playerB,moveB);
            if(moveB == SPECIAL)
                playerB.special(playerA,moveA);
        }
        playerA.unStun(); // decrement stun after each duel
        playerB.unStun();
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
        if(playerA.getStun()==0)
        {
            cout << "Player 1, act" << endl;
            moveA = input(playerA);
        }
        else
        {
            cout << "Player 1, you're stunned!" << '\n' << "Press enter to continue" << endl;
            moveA = CHARGE;
            cin.ignore();
            cin.get();
        }
        cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' ;
        cout << "Player 1 health: " << playerA.getHealth() << endl;
        cout << "Player 1 meter:  " << playerA.getMeter() << endl;
        cout << "Player 2 health: " << playerB.getHealth() << endl;
        cout << "Player 2 meter:  " << playerB.getMeter() << endl << endl;
        if(playerB.getStun()==0)
        {
            cout << "Player 2, act" << endl;
            moveB = input(playerB);
        }
        else
        {
            cout << "Player 2, you're stunned!" << '\n' << "Press enter to continue" << endl;
            moveB = CHARGE;
            cin.ignore();
            cin.get();
        }
        string crit = duel(moveA,moveB);
        cout << endl << crit;

        cout << endl << endl << "OUTCOME OF ROUND " << ROUND << ":" << endl << endl;
        cout << "Player 1 action: " << moves[moveA] << endl;
        cout << "Player 2 action: " << moves[moveB] << endl << endl;

        if(playerA.getStun()!=0)
        {
            cout << "Player 1 is stunned!" << endl;
        }
        else if (playerB.getStun()!=0)
        {
            cout << "Player 2 is stunned!" << endl;
        }

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
