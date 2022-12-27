#include "DominoCarreJoueurGUI.hpp"

DominoCarreJoueurGUI::DominoCarreJoueurGUI(Joueur<DominoCarreTuile>* joueur, const sf::Font* font): joueur { joueur }, font { font } {
    rectangle.setFillColor(sf::Color::White);
    name.setFont(*font);
    name.setFillColor(sf::Color::Black);
    score.setFont(*font);
    score.setFillColor(sf::Color::Black);
    updateValues();
}

void DominoCarreJoueurGUI::updateValues() {
    name.setString(joueur->getName());
    score.setString(std::to_string(joueur->getScore()));
}

void DominoCarreJoueurGUI::setSize(const float x, const float y) {
    rectangle.setSize(sf::Vector2f { x, y });
    name.setCharacterSize(y / 2);
    score.setCharacterSize(y / 2);
    score.setPosition(0, name.getLocalBounds().top + name.getLocalBounds().height);
}

void DominoCarreJoueurGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(name, states);
    target.draw(score, states);
}
