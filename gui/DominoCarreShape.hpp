#ifndef _DominoCarreShape
#define _DominoCarreShape

#include "../DominoCarre.hpp"
#include <iostream>

class DominoCarreShape {
    private:
        vector<Tuile> sacTuiles;
        vector<vector<Tuile>> plateau;

    public:
        DominoCarreShape(vector <Tuile> sacTuiles);
        Tuile piocherTuile();
        void placerTuile(int x, int y, int orientation);
        void tournerTuile(int x, int y);
        void sauvegarderPartie();
        void chargerPartie();
        void afficherAide();
        void afficherRegles();
        void quitter();
};


#endif