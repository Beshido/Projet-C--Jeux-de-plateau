#ifndef _DominoCarre
#define _DominoCarre

#include "DominoCarreTile.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"

class DominoCarre: public Plateau<DominoCarreTile> {
    public:
        DominoCarre(const size_t size, const size_t amountPlayers);
        virtual const bool isPlayable(const DominoCarreTile* tuile, const size_t x, const size_t y) const;
        virtual const bool isFinished() const;
        virtual void updateScore(const size_t x, const size_t y);
        virtual const bool isNextPlayerTurn() const;

    private:
        static const unsigned int MIN_VALUE;
        static const unsigned int MAX_VALUE;
        static const unsigned int SIZE;
        static std::vector<unsigned int> values;
        static int pickRandomElement(const std::vector<int>& vec);
        static int generateRandomInt();

        const int sumDigits(const unsigned int n) const;
};

#endif