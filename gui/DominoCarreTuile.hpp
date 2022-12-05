#ifndef _DominoCarreTuile
#define _DominoCarreTuile

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Tuile.hpp"

class DominoCarreTuile : public sf::Drawable, public sf::Transformable {

    public:
        DominoCarreTuile(Tuile* dominoCarre, sf::Font* font);
        void setSize(float size);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Tuile* dominoCarre;
        sf::RectangleShape carre;
        sf::Text nombreHaut;
        sf::Text nombreGauche;
        sf::Text nombreDroite;
        sf::Text nombreBas;
};

#endif