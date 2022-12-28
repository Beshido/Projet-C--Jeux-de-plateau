#include "Bouton.hpp"
#include <iostream>

const unsigned int Bouton::DEFAULT_WIDTH = 300;
const unsigned int Bouton::DEFAULT_HEIGHT = 300;

Bouton::Bouton(const std::string label): rectangle { sf::RectangleShape { sf::Vector2f { DEFAULT_WIDTH, DEFAULT_HEIGHT } } }, text { sf::Text { label, Assets::font, DEFAULT_HEIGHT / 2 } } {
    text.setFillColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::White);
}

const sf::Vector2f Bouton::getSize() const {
    return rectangle.getSize();
}

void Bouton::setSize(const float width, const float height) {
    rectangle.setSize(sf::Vector2f { width, height });
    text.setCharacterSize(height / 2);
}

void Bouton::setTextColor(const sf::Color color) {
    text.setFillColor(color);
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
    target.draw(text, states);
}