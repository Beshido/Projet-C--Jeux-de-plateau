#ifndef _DominoCarreTuileGUI
#define _DominoCarreTuileGUI

#include "../../Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class DominoCarreTuileGUI : public sf::Drawable, public sf::Transformable {
    public:
        DominoCarreTuileGUI(const Tuile<unsigned int>* dominoCarre, const sf::Font* font);
        const Tuile<unsigned int>* getTuile() const;
        const float getTaille() const;
        void setSize(const float taille);
        void updateValeurs();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        static const unsigned int DEFAULT_SIZE;
        const Tuile<unsigned int>* dominoCarre;
        sf::RectangleShape carre;
        sf::Text nombreNord;
        sf::Text nombreOuest;
        sf::Text nombreEst;
        sf::Text nombreSud;
};

#endif