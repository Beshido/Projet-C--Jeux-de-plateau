#ifndef _Bouton
#define _Bouton

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Bouton: public sf::Drawable, public sf::Transformable {
    public:
        Bouton(float x, float y, float width, float height, sf::Color couleurRectangle, std::string label, sf::Font* font, sf::Color couleurTexte);
        Bouton(float x, float y, float width, float height, std::string label, sf::Font* font);
        bool checkClick(sf::Event event);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::RectangleShape rectangle;
        sf::Color couleurRectangle;
        sf::Text texte;
        sf::Color couleurTexte;
};

#endif