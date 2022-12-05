#include "DominoCarreTuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Tuile.hpp"

DominoCarreTuile::DominoCarreTuile(Tuile* dominoCarre, sf::Font* font):
    dominoCarre { dominoCarre },
    carre { sf::RectangleShape(sf::Vector2f(300, 300)) },
    nombreHaut { sf::Text(std::to_string(dominoCarre->getValeurNord()), *font) },
    nombreGauche { sf::Text(std::to_string(dominoCarre->getValeurOuest()), *font) },
    nombreDroite { sf::Text(std::to_string(dominoCarre->getValeurEst()), *font) },
    nombreBas { sf::Text(std::to_string(dominoCarre->getValeurSud()), *font) } {
        carre.setFillColor(sf::Color::White);

        nombreHaut.setOrigin(0, nombreHaut.getLocalBounds().height + nombreHaut.getLocalBounds().top);
        nombreHaut.setFillColor(sf::Color::Black);

        nombreGauche.setFillColor(sf::Color::Green);
        nombreGauche.setRotation(90);

        nombreDroite.setOrigin(0, nombreDroite.getLocalBounds().height + nombreDroite.getLocalBounds().top);
        nombreDroite.move(carre.getSize().x, 0);
        nombreDroite.setFillColor(sf::Color::Red);
        nombreDroite.rotate(90);

        nombreBas.move(0, carre.getSize().y);
        nombreBas.setFillColor(sf::Color::Yellow);
    }

void DominoCarreTuile::setSize(float size) {
    carre.setSize(sf::Vector2f(size, size));
    nombreHaut.setCharacterSize(size / 3);
    nombreGauche.setCharacterSize(size / 3);
    nombreDroite.setCharacterSize(size / 3);
    nombreBas.setCharacterSize(size / 3);
}


void DominoCarreTuile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(carre, states);
    target.draw(nombreHaut, states);
    target.draw(nombreDroite, states);
    target.draw(nombreBas, states);
    target.draw(nombreGauche, states);
}