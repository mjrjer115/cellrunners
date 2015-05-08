//#include "CellRunners.h"
#include "player.h"
#include "game.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    enum{STR,DEF,INL,WIS,SPD};
    enum{NIL,EVE};
    player A(3,3);
    player B(4,2);
    A.setCharacter(NIL);
    B.setCharacter(EVE);

    /*
    A.setStat(3,STR);
    A.setStat(0,DEF);
    A.setStat(0,INL);
    A.setStat(0,WIS);
    A.setStat(4,SPD);
    B.setStat(4,STR);
    B.setStat(0,DEF);
    B.setStat(0,INL);
    B.setStat(0,WIS);
    B.setStat(3,SPD);
    */
//  cout << A.getStat(2);
//  cout << "player A hp " << A.getHealth() << endl;
//  cout << "player B hp " << B.getHealth() << endl;
//  cout << "player A meter " << A.getMeter() << endl;
//  cout << "player B meter " << B.getMeter() << endl;
    game G(A,B);
    G.run();
    cout << "Press enter to exit." << endl;
    cin.ignore();
    cin.get();
    return 0;
}
