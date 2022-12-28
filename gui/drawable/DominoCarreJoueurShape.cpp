#include "DominoCarreJoueurShape.hpp"

DominoCarreJoueurShape::DominoCarreJoueurShape(Joueur<DominoCarreTuile>* joueur): PlayerShape<Joueur<DominoCarreTuile>> { joueur } {
    score.setFont(Assets::font);
    score.setFillColor(sf::Color::Black);
    update();
}

void DominoCarreJoueurShape::update() {
    score.setString(std::to_string(player->getScore()));
}

void DominoCarreJoueurShape::setSize(const float x, const float y) {
    PlayerShape<Joueur<DominoCarreTuile>>::setSize(x, y);

    score.setCharacterSize(y / 2);
    score.setPosition(0, name.getLocalBounds().top + name.getLocalBounds().height);
}

void DominoCarreJoueurShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(name, states);
    target.draw(score, states);
}
