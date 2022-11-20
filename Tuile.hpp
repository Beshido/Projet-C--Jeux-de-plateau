#ifndef _Tuile
#define _Tuile

#include "Tuile.hpp"

#include <iostream>
using namespace std;

class Tuile{
private:
    int valeurNord;
    int valeurSud;
    int valeurEst;
    int valeurOuest;

public:
    Tuile(int valeurNord, int valeurSud, int valeurEst, int valeurOuest);

};



#endif