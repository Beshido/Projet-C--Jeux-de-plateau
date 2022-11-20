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
    vector<Tuile> plateau;

public:
    DominoCarre(vector <Tuile> sacTuiles);
    void afficherSac();
    void afficherPlateau();
    void melangerSac();
    void distribuerTuiles();
    void placerTuile(int x, int y, int orientation);
    void tournerTuile(int x, int y);
    void deplacerTuile(int x1, int y1, int x2, int y2);
    void supprimerTuile(int x, int y);
    void sauvegarderPartie();
    void chargerPartie();
    void afficherAide();
    void afficherRegles();
    void quitter();
};


#endif