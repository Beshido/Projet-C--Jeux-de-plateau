#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarre.hpp"
#include "Tuile.hpp"
#include <iostream>
#include <random>
#include <vector>

class DominoCarre {
    private:
        static const unsigned int MIN_VALUE;
        static const unsigned int MAX_VALUE;

        const unsigned int longueur;
        const unsigned int hauteur;
        vector<Tuile<unsigned int>> sacTuiles;
        vector<vector<Tuile<unsigned int>>> plateau;

    public:
        DominoCarre(const unsigned int longueur, const unsigned int hauteur, const unsigned int taille);
        const Tuile<unsigned int> piocherTuile();
        void placerTuile(int x, int y, Tuile<unsigned int> tuile, vector<vector<Tuile<unsigned int>>> plateau);
        void sauvegarderPartie();
        void chargerPartie();
        void afficherAide();
        void afficherRegles();
        void quitter();
        const unsigned int getLongueur() const;
        const unsigned int getHauteur() const;
        const vector<vector<Tuile<unsigned int>>> getPlateau() const;
};


#endif