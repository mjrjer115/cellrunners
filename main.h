#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "player.h"
int charselect()
{
    enum{NIL,EVE,LANCER};
    std::string select;
    while(true)
    {
        std::cin >> select;
        if(select == "1")
            return NIL;
        else if(select == "2")
            return EVE;
        else if(select == "3")
            return LANCER;
        else std::cout << "Bad input." << std::endl;
    }
}


#endif // MAIN_H_INCLUDED
