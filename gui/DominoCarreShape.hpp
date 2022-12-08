#ifndef _DominoCarreShape
#define _DominoCarreShape

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Tuile.hpp"

class DominoCarreShape : public sf::Drawable {

    public:
        DominoCarreShape(Tuile* dominoCarre);

    private:
        sf::Text nombreHaut;
        sf::Text nombreDroite;
        sf::Text nombreBas;
        sf::Text nombreGauche;

};


#endif