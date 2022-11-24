#include "Bouton.hpp"
#include <iostream>
#include <string>

Bouton::Bouton(std::string texte, float x, float y, float width, float height, sf::Color couleur): 
    texte { sf::String(texte) }, 
    x { x },
    y { y },
    width { width },
    height { height },
    rectangle { sf::RectangleShape(sf::Vector2f(width, height)) },
    couleur { couleur } {
        rectangle.setPosition(x, y);
        rectangle.setFillColor(couleur);
    }

void Bouton::checkClick(sf::Event event) {
    if (event.type != sf::Event::MouseButtonPressed) 
        return;
    if (event.mouseButton.x > rectangle.getPosition().x 
        && event.mouseButton.x < rectangle.getPosition().x + rectangle.getSize().x
        && event.mouseButton.y > rectangle.getPosition().y 
        && event.mouseButton.y < rectangle.getPosition().y + rectangle.getSize().y) {
            std::cout << "Le bouton a été cliqué !" << std::endl;
        }
}

sf::RectangleShape Bouton::getRectangle() {
    return this->rectangle;
}