#ifndef _Trax
#define _Trax

#include "TraxTile.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"

class Trax: public Plateau<TraxTile> {
    public:
        Trax();
        virtual const bool isPlayable(const TraxTile* tuile, const size_t x, const size_t y) const;
        virtual const bool isFinished() const;
        virtual const bool isNextPlayerTurn() const;
        virtual void updateScore(const size_t x, const size_t y);
        virtual const Joueur<TraxTile>* getWinner() const;

    private:
        static const unsigned int SIZE;
        bool firstPlay;

        const bool isForcedMoveAvailable() const;
        const bool isForcedMove(const size_t x, const size_t y) const;
        const bool isFinishedRecursive(const TraxCouleur color, const size_t sourceX, const size_t sourceY, const TraxTile* previousTile, const size_t x, const size_t y, const bool first = false) const;
};

#endif
