#include "DominoCarreTuileGUI.hpp"

const unsigned int DominoCarreTuileGUI::DEFAULT_SIZE = 300;

DominoCarreTuileGUI::DominoCarreTuileGUI(const Tuile<unsigned int>* dominoCarre, const sf::Font* font):
    dominoCarre { dominoCarre },
    carre { sf::RectangleShape {} } {
        carre.setFillColor(sf::Color::White);
        carre.setOutlineColor(sf::Color::Black);
        carre.setOutlineThickness(1);

        nombreNord.setFont(*font);
        nombreNord.setFillColor(sf::Color::Black);

        nombreOuest.setFont(*font);
        nombreOuest.setFillColor(sf::Color::Green);
        nombreOuest.setLineSpacing(0.5);
        
        nombreEst.setFont(*font);
        nombreEst.setFillColor(sf::Color::Red);
        nombreEst.setLineSpacing(0.5);
        
        nombreSud.setFont(*font);
        nombreSud.setFillColor(sf::Color::Blue);

        updateValeurs();
    }

const Tuile<unsigned int>* DominoCarreTuileGUI::getTuile() const {
    return dominoCarre;
}

const float DominoCarreTuileGUI::getTaille() const {
    return carre.getSize().x;
}

void DominoCarreTuileGUI::setSize(const float taille) {
    carre.setSize(sf::Vector2f(taille, taille));

    unsigned int characterSize = taille / 4;

    nombreNord.setCharacterSize(characterSize);
    nombreNord.setOrigin(nombreNord.getLocalBounds().width / 2 + nombreNord.getLocalBounds().left, nombreNord.getLocalBounds().top);
    nombreNord.move(taille / 2, 0);

    nombreOuest.setCharacterSize(characterSize);
    nombreOuest.setOrigin(nombreNord.getLocalBounds().left, nombreOuest.getLocalBounds().height / 2 + nombreOuest.getLocalBounds().top);
    nombreOuest.move(0, taille / 2);

    nombreEst.setCharacterSize(characterSize);
    nombreEst.setOrigin(nombreEst.getLocalBounds().width + nombreEst.getLocalBounds().left, nombreEst.getLocalBounds().height / 2 + nombreEst.getLocalBounds().top);
    nombreEst.move(taille, taille / 2);

    nombreSud.setCharacterSize(characterSize);
    nombreSud.setOrigin(nombreSud.getLocalBounds().width / 2 + nombreSud.getLocalBounds().left, nombreSud.getLocalBounds().height + nombreSud.getLocalBounds().top);
    nombreSud.move(taille / 2, taille);
}

void DominoCarreTuileGUI::updateValeurs() {
    nombreNord.setString(std::to_string(dominoCarre->getValeurNord()));
    std::string valeurOuest = std::to_string(dominoCarre->getValeurOuest());
    for (size_t i = 1; i < valeurOuest.length(); i += 2) {
        valeurOuest.insert(i, "\n");
    }
    nombreOuest.setString(valeurOuest);
    std::string valeurEst = std::to_string(dominoCarre->getValeurEst());
    for (size_t i = 1; i < valeurEst.length(); i += 2) {
        valeurEst.insert(i, "\n");
    }
    nombreEst.setString(valeurEst);
    nombreSud.setString(std::to_string(dominoCarre->getValeurSud()));
}

void DominoCarreTuileGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(carre, states);
    target.draw(nombreNord, states);
    target.draw(nombreOuest, states);
    target.draw(nombreEst, states);
    target.draw(nombreSud, states);
}