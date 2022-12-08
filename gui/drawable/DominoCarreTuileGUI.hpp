#ifndef _DominoCarreTuileGUI
#define _DominoCarreTuileGUI

#include "../../Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class DominoCarreTuileGUI : public sf::Drawable, public sf::Transformable {
    public:
        DominoCarreTuileGUI(Tuile<int>* dominoCarre, sf::Font* font);
        Tuile<int>* getTuile();
        void setSize(float size);
        void updateValues();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Tuile<int>* dominoCarre;
        sf::RectangleShape carre;
        sf::Text nombreNord;
        sf::Text nombreOuest;
        sf::Text nombreEst;
        sf::Text nombreSud;
};

#endif