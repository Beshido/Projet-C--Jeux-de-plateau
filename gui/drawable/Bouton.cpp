#include "Bouton.hpp"

const unsigned int Bouton::DEFAULT_WIDTH = 300;
const unsigned int Bouton::DEFAULT_HEIGHT = 300;

Bouton::Bouton(const std::string label, const sf::Font* font): 
    rectangle { sf::RectangleShape { sf::Vector2f { DEFAULT_WIDTH, DEFAULT_HEIGHT } } },
    texte { sf::Text { label, *font, DEFAULT_HEIGHT / 2 } } {
        texte.setFillColor(sf::Color::Black);
        rectangle.setFillColor(sf::Color::White);
    }

const sf::Vector2f Bouton::getSize() const {
    return rectangle.getSize();
}

void Bouton::setSize(const float width, const float height) {
    rectangle.setSize(sf::Vector2f { width, height });
    texte.setCharacterSize(height / 2);
}

void Bouton::setTextColor(const sf::Color color) {
    texte.setFillColor(color);
}

void Bouton::setRectangleColor(const sf::Color color) {
    rectangle.setFillColor(color);
}

void Bouton::setOnClickListener(const std::function<int()> onClick) {
    this->onClick = onClick;
}

const bool Bouton::isClicked(const float x, const float y) const {
    return sf::FloatRect { getPosition(), getSize() }.contains(x, y);
}

const void Bouton::fireEvent() const {
    onClick();
}

void Bouton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(texte, states);
}