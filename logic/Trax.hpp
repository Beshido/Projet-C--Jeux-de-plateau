#ifndef _Trax.hpp
#define _Trax.hpp

#include "TraxTuile.hpp"

class TraxTuile: public Tuile<unsigned int> {
    public:
        Trax(const size_t taille, const size_t nombreJoueurs);
        const bool isFinished() const;
        virtual void nextPlayer();
        virtual const Joueur<TraxTuile>* getWinner() const;
        using Tuile<unsigned int>::Tuile;
        TraxTuile(); // <--- This is the constructor

    private:
        bool IsSurrounded() const {};
        static const unsigned int SIZE;
        void Trax::forcedPlay();

}