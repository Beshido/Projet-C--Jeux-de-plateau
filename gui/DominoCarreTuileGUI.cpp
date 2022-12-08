#include "DominoCarreTuileGUI.hpp"

DominoCarreTuileGUI::DominoCarreTuileGUI(Tuile<int>* dominoCarre, sf::Font* font):
    dominoCarre { dominoCarre },
    carre { sf::RectangleShape(sf::Vector2f(300, 300)) },
    nombreNord { sf::Text(std::to_string(dominoCarre->getValeurNord()), *font) },
    nombreOuest { sf::Text(std::to_string(dominoCarre->getValeurOuest()), *font) },
    nombreEst { sf::Text(std::to_string(dominoCarre->getValeurEst()), *font) },
    nombreSud { sf::Text(std::to_string(dominoCarre->getValeurSud()), *font) } {
        std::string valeurOuest = std::to_string(dominoCarre->getValeurOuest());
        valeurOuest.insert(3, "\n");
        valeurOuest.insert(2, "\n");
        valeurOuest.insert(1, "\n");
        nombreOuest.setString(valeurOuest);

        std::string valeurEst = std::to_string(dominoCarre->getValeurEst());
        valeurEst.insert(3, "\n");
        valeurEst.insert(2, "\n");
        valeurEst.insert(1, "\n");
        nombreEst.setString(valeurEst);

        carre.setFillColor(sf::Color::White);

        nombreNord.move(carre.getSize().x / 2, 0);
        nombreNord.setLetterSpacing(10);
        nombreNord.setOrigin(nombreNord.getLocalBounds().width / 2, 0);
        nombreNord.setFillColor(sf::Color::Black);

        nombreOuest.move(0, carre.getSize().y / 2);
        nombreOuest.setOrigin(0, nombreOuest.getLocalBounds().height / 2);
        nombreOuest.setFillColor(sf::Color::Green);

        nombreEst.move(carre.getSize().x, carre.getSize().y / 2);
        nombreEst.setOrigin(nombreEst.getLocalBounds().width, nombreEst.getLocalBounds().height / 2);
        nombreEst.setFillColor(sf::Color::Red);

        nombreSud.move(carre.getSize().x / 2, carre.getSize().y - nombreSud.getLocalBounds().height * 2);
        nombreSud.setLetterSpacing(10);
        nombreSud.setOrigin(nombreSud.getLocalBounds().width / 2, 0);
        nombreSud.setFillColor(sf::Color::Blue);
    }

Tuile<int>* DominoCarreTuileGUI::getTuile() {
    return dominoCarre;
}

void DominoCarreTuileGUI::setSize(float size) {
    carre.setSize(sf::Vector2f(size, size));
    nombreNord.setCharacterSize(size / 3);
    nombreOuest.setCharacterSize(size / 3);
    nombreEst.setCharacterSize(size / 3);
    nombreSud.setCharacterSize(size / 3);
}

void DominoCarreTuileGUI::updateValues() {
    std::string valeurOuest = std::to_string(dominoCarre->getValeurOuest());
    valeurOuest.insert(3, "\n");
    valeurOuest.insert(2, "\n");
    valeurOuest.insert(1, "\n");
    nombreOuest.setString(valeurOuest);

    std::string valeurEst = std::to_string(dominoCarre->getValeurEst());
    valeurEst.insert(3, "\n");
    valeurEst.insert(2, "\n");
    valeurEst.insert(1, "\n");
    nombreEst.setString(valeurEst);

    nombreNord.setString(std::to_string(dominoCarre->getValeurNord()));
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