#ifndef _Carcassone
#define _Carcassone

#include "CarcassoneTile.hpp"

class Carcassone : public Plateau<CarcassoneTuile> {
    public:
        Carcassone(const size_t taille, const size_t nombreJoueurs);
        virtual const bool isFinished() const;
        virtual void isNextPlayerTurn();
        virtual const Joueur<CarcassoneTuile>* getWinner() const;
        Joueur<CarcassoneTuile>* DetermineWinner();

    private:
        static const unsigned int SIZE;
        static const unsigned int MIN_VALUE;
        bool last_tile_placed_;  // Whether the last tile has been placed
        int remaining_tiles_;  // The number of tiles remaining to be played
        const unsigned int kMaxScore = 25;  // The maximum score a player can have
};

#endif