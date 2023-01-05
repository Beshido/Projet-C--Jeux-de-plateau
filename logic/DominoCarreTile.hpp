#ifndef _DominoCarreTile
#define _DominoCarreTile

#include "Tile.hpp"

class DominoCarreTile: public Tile<unsigned int> {
    public:
        using Tile<unsigned int>::Tile;
        const std::string getValeurNordString() const;
        const std::string getValeurOuestString() const;
        const std::string getValeurEstString() const;
        const std::string getValeurSudString() const;
        void tournerGauche();
        void tournerDroite();

    private:
        const unsigned int reverseDigits(const unsigned int value) const;
        const std::string toThreeDigitsString(const unsigned int value) const;
        const std::string toVerticalString(const std::string text) const;
        bool IsSurrounded() const;
};

#endif