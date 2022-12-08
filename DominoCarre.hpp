#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarre.hpp"
#include "Tuile.hpp"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class DominoCarre {
    private:
        vector<Tuile<int>> sacTuiles;
        vector<vector<Tuile<int>>> plateau;

    public:
        DominoCarre(vector<Tuile<int>> sacTuiles);
        Tuile<int> piocherTuile();
        void placerTuile(int x, int y, Tuile<int> tuile, vector<vector<Tuile<int>>> plateau);
        void sauvegarderPartie();
        void chargerPartie();
        void afficherAide();
        void afficherRegles();
        void quitter();
};


#endif