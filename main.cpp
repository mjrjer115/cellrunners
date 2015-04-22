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
//  cout << "player A hp " << A.getHealth() << endl;
//  cout << "player B hp " << B.getHealth() << endl;
//  cout << "player A meter " << A.getMeter() << endl;
//  cout << "player B meter " << B.getMeter() << endl;
    game G(A,B);
    G.run();
    cout << "Press enter to exit" << endl;
    cin.ignore();
    cin.get();
    return 0;
}
