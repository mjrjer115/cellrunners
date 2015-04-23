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
    player A(3,1);
    player B(3,1);
    A.setStat(1,STR);
    A.setStat(1,DEF);
    A.setStat(1,INL);
    A.setStat(1,WIS);
    A.setStat(1,SPD);
    B.setStat(1,STR);
    B.setStat(1,DEF);
    B.setStat(1,INL);
    B.setStat(1,WIS);
    B.setStat(1,SPD);
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
