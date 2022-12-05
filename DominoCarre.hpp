#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarre.hpp"
#include <vector>
#include "Tuile.hpp"


#include <iostream>
using namespace std;

class DominoCarre{
private:
    vector<Tuile> sacTuiles;
    vector<vector<Tuile>> plateau;

public:
    DominoCarre(vector <Tuile> sacTuiles);
    Tuile piocherTuile();
    void placerTuile(int x, int y, Tuile tuile, vector<vector<Tuile>> plateau);
    void sauvegarderPartie();
    void chargerPartie();
    void afficherAide();
    void afficherRegles();
    void quitter();
};


#endif