#ifndef _Carcassone
#define _Carcassone

#include "CarcassoneTile.hpp"
#include "Plateau.hpp"

class Carcassone : public Plateau<CarcassoneTile> {
    public:
        Carcassone();
        const bool isSurrounded(const size_t x, const size_t y) const;
        const bool isCompleted(const size_t x, const size_t y) const;
        const bool placePartisan(const size_t x, const size_t y, Partisan partisan);
        const bool checkMonasteryRules(const size_t x, const size_t y) const;
        
        virtual const bool isFinished() const;
        virtual const bool isNextPlayerTurn() const;
        virtual const bool isPlayable(const CarcassoneTile* tuile, const size_t x, const size_t y) const;
        virtual void updateScore(const size_t x, const size_t y);

    private:
        std::vector<std::vector<std::vector<Partisan>>> playedPartisans;
        static const size_t SIZE;
};

#endif