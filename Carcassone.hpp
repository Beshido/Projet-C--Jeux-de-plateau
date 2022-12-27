#ifndef _Carcassone
#define _Carcassone

#include "CarcassoneTuile.hpp"

class Carcassone : public Plateau<CarcassoneTuile> {
    public:
        Carcassone(const size_t taille, const size_t nombreJoueurs);
        bool isFinished() const;
        virtual void nextPlayer();
        virtual const Joueur<CarcassoneTuile>* getWinner() const;
        Joueur* DetermineWinner();

    private:
        static const unsigned int SIZE;
        static const unsigned int MIN_VALUE;
        std::vector<Joueur*> players_;  // The players in the game
        bool last_tile_placed_;  // Whether the last tile has been placed
        int remaining_tiles_;  // The number of tiles remaining to be played
        const unsigned int kMaxScore = 25;  // The maximum score a player can have
        unsigned int current_player_;  // The index of the current player

};