#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarreTuile.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"

class DominoCarre: public Plateau<DominoCarreTuile> {
    public:
        DominoCarre(const size_t taille, const size_t nombreJoueurs);
        virtual const bool isFinished() const;
        virtual void nextPlayer();
        virtual const Joueur<DominoCarreTuile>* getWinner() const;

    private:
        static const unsigned int MIN_VALUE;
        static const unsigned int MAX_VALUE;
        static const unsigned int SIZE;
};

#endif