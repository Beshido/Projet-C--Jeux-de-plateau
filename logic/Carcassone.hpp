#ifndef _Carcassone
#define _Carcassone

#include "CarcassoneTile.hpp"
#include "Plateau.hpp"

class Carcassone : public Plateau<CarcassoneTile> {
    public:
        Carcassone();
        const bool isSurrounded(const size_t x, const size_t y) const;
        const bool isCompleted(const size_t x, const size_t y) const;
        
        virtual const bool isFinished() const;
        virtual const bool isNextPlayerTurn() const;
        virtual const bool isPlayable(const CarcassoneTile* tuile, const size_t x, const size_t y) const;
        virtual void updateScore(const size_t x, const size_t y);

    private:
        static const size_t SIZE;
};

#endif