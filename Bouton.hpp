#ifndef _Bouton
#define _Bouton

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Bouton {
    public:
        Bouton(std::string texte, float x, float y, float width, float height, sf::Color couleur);
        void checkClick(sf::Event event);
        sf::RectangleShape getRectangle();

    private:
        float x;
        float y;
        float width;
        float height;
        sf::String texte;
        sf::RectangleShape rectangle;
        sf::Color couleur;
};

#endif