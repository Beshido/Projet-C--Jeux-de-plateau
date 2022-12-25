#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarre.hpp"
#include "Joueur.hpp"
#include "Tuile.hpp"
#include <iostream>
#include <random>
#include <vector>

class DominoCarre {
    private:
        static const unsigned int MIN_VALUE;
        static const unsigned int MAX_VALUE;
        static const unsigned int SIZE;

        std::vector<Tuile<unsigned int>*> sacTuiles;
        std::vector<std::vector<Tuile<unsigned int>*>> plateau;
        std::vector<Joueur<unsigned int>*> joueurs;

    public:
        DominoCarre(const unsigned int taille, const unsigned int nombreJoueurs);
        Tuile<unsigned int>* piocherTuile();
        const bool placerTuile(Tuile<unsigned int>* tuile, const size_t x, const size_t y);
        const bool isPlayable(const Tuile<unsigned int>* tuile, const size_t x, const size_t y) const;
        const bool isPlayable(const Tuile<unsigned int>* tuile) const;
        const unsigned int getLongueur() const;
        const unsigned int getHauteur() const;
        const std::vector<std::vector<Tuile<unsigned int>*>> getPlateau() const;
};

#endif