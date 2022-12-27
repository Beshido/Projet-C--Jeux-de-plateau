#ifndef _DominoCarre
#define _DominoCarre

#include "Plateau.hpp"
#include "DominoCarre.hpp"
#include "DominoCarreTuile.hpp"
#include "Joueur.hpp"
#include "Tuile.hpp"
#include <iostream>
#include <random>
#include <vector>

class DominoCarre : public Plateau<DominoCarreTuile> {
    public:
        DominoCarre(const size_t taille, const size_t nombreJoueurs);
        const bool isFinished() const;
        /* virtual const Joueur<DominoCarreTuile>* getWinner() const; */

    private:
        static const unsigned int MIN_VALUE;
        static const unsigned int MAX_VALUE;
        static const unsigned int SIZE;
};

#endif