#include "Bouton.hpp"
#include <iostream>
#include <string>

Bouton::Bouton(float x, float y, float width, float height, sf::Color couleurRectangle, std::string label, sf::Font* font, sf::Color couleurTexte): 
    rectangle { sf::RectangleShape(sf::Vector2f(width, height)) },
    couleurRectangle { couleurRectangle }, 
    texte { sf::Text(label, *font, height / 2) },
    couleurTexte { couleurTexte } {
        rectangle.setPosition(x, y);
        rectangle.setFillColor(couleurRectangle);

        texte.setPosition(x, y);
        texte.setFillColor(couleurTexte);
    }

Bouton::Bouton(float x, float y, float width, float height, std::string label, sf::Font* font) : Bouton(x, y, width, height, sf::Color::White, label, font, sf::Color::Black) {}

bool Bouton::checkClick(sf::Event event) {
    if (event.type != sf::Event::MouseButtonPressed) 
        return false;
    return (event.mouseButton.x > rectangle.getPosition().x 
        && event.mouseButton.x < rectangle.getPosition().x + rectangle.getSize().x
        && event.mouseButton.y > rectangle.getPosition().y 
        && event.mouseButton.y < rectangle.getPosition().y + rectangle.getSize().y);
}

void Bouton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(texte, states);
}