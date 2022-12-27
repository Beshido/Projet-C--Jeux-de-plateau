#ifndef _DominoCarreTuile
#define _DominoCarreTuile

#include "Tuile.hpp"

class DominoCarreTuile: public Tuile<unsigned int> {
    public:
        using Tuile<unsigned int>::Tuile;
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
};

#endif