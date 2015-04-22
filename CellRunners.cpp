/* #include "CellRunners.h"
using namespace std;

game::game(player A, player B)
{
    playerA = A;
    playerB = B;
}

enum {CHARGE, ATTACK, BLOCK, SPECIAL};

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
        }

        else if(moveB == BLOCK)
            this -> playerB.chargeGain();

        else if(moveB == SPECIAL)
            this -> playerB.healthLoss();
            this -> playerB.chargeLoss(3);

        else
            this -> playerB.healthLoss();
    }
    else if(moveA == BLOCK)
    {
        if(moveB == ATTACK)
            this -> playerA.chargeGain();
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
};

/* void game::computer()
{

};
*/
/*
int input(player A)
{
    string thong;     //shawn is gay so this is actually input
    while(true)
    {
        cin >> thong;
        if(thong == "c") return 0;
        else if(thong == "a")
        {
            if(A.getMeter() > 0) return 1;
            else cout << "You don't have enough meter." << endl;
        }
        else if(thong == "b") return 2;
        else if(thong == "s")
        {
            if(A.getMeter() > 2) return 3; //will change the number 2 to player.maxMeter and write it
            else cout << "You don't have enough meter." << endl;
        }
        else cout << "Bad input." << endl;
    }
};

void game::run()
{
    int moveA, moveB;
    int ROUND = 1;
    string moves[4]={"Charge","Attack","Block","Special"};
    cout << "Welcome!" << endl;
    while(playerA.getHealth > 0 && playerB.getHealth > 0)
    {
        cout << "Player 1, act" << endl;
        moveA = input(playerA);
        cout << "Player 2, act" << endl;
        moveB = input(playerB);
        duel(moveA,moveB);
        cout << "OUTCOME OF ROUND " << ROUND << ":" << endl << endl;
        cout << "Player 1 action: " << moves[moveA] << endl;
        cout << "Player 2 action: " << moves[moveB] << endl << endl;
        cout << "Player 1 health: " << playerA.getHealth << endl;
        cout << "Player 1 meter:  " << playerA.getMeter << endl;
        cout << "Player 2 health: " << playerB.getHealth << endl;
        cout << "Player 2 meter:  " << playerB.getMeter << endl;
        ROUND++;
    }
    if (playerA.getHealth > 0)
    {
        cout << "Player 1 wins!"
    }
};
*/
