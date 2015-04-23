//#include "CellRunners.h"
#include "player.h"
#include "game.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    player A(3,1);
    player B(3,1);
    A.setIntelligence(1);
    B.setIntelligence(1);
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
