#ifndef _Trax
#define _Trax

#include "TraxTile.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"

class Trax: public Plateau<TraxTile> {
    public:
        Trax();
        virtual const bool isFinished() const;
        virtual void nextPlayer();
        virtual const Joueur<TraxTile>* getWinner() const;

    private:
        static const unsigned int SIZE;
};

#endif