#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarreTuile.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"

class DominoCarre: public Plateau<DominoCarreTuile> {
    public:
        DominoCarre(const size_t size, const size_t amountPlayers);
        virtual const bool isPlayable(const DominoCarreTuile* tuile, const size_t x, const size_t y) const;
        virtual const bool isFinished() const;
        virtual void updateScore(const size_t x, const size_t y);
        virtual const bool isNextPlayerTurn() const;
        virtual const Joueur<DominoCarreTuile>* getWinner() const;

    private:
        static const unsigned int MIN_VALUE;
        static const unsigned int MAX_VALUE;
        static const unsigned int SIZE;

        const int sumDigits(const unsigned int n) const;
};

#endif