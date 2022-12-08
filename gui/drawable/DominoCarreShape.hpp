#ifndef _DominoCarreShape
#define _DominoCarreShape

#include "../../Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class DominoCarreShape : public sf::Drawable {
    public:
        DominoCarreShape(Tuile<int>* dominoCarre);

    private:
        sf::Text nombreHaut;
        sf::Text nombreDroite;
        sf::Text nombreBas;
        sf::Text nombreGauche;

};


#endif