#include "DominoCarreTuileGUI.hpp"

const unsigned int DominoCarreTuileGUI::DEFAULT_SIZE = 300;

DominoCarreTuileGUI::DominoCarreTuileGUI(DominoCarreTuile* dominoCarre, const sf::Font* font): dominoCarre { dominoCarre }, carre { sf::RectangleShape { sf::Vector2f { DEFAULT_SIZE, DEFAULT_SIZE } } } {
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

    updateValues();
}

DominoCarreTuileGUI::~DominoCarreTuileGUI() {
    std::cout << "Destruction de DominoCarreTuileGUI." << std::endl;
}

DominoCarreTuile* DominoCarreTuileGUI::getTuile() const {
    return dominoCarre;
}

void DominoCarreTuileGUI::setSize(const float size) {
    carre.setSize(sf::Vector2f(size, size));

    unsigned int characterSize = size / 4;

    nombreNord.setCharacterSize(characterSize);
    nombreNord.setOrigin(nombreNord.getLocalBounds().width / 2 + nombreNord.getLocalBounds().left, nombreNord.getLocalBounds().top);
    nombreNord.setPosition(size / 2, 0);

    nombreOuest.setCharacterSize(characterSize);
    nombreOuest.setOrigin(nombreNord.getLocalBounds().left, nombreOuest.getLocalBounds().height / 2 + nombreOuest.getLocalBounds().top);
    nombreOuest.setPosition(0, size / 2);

    nombreEst.setCharacterSize(characterSize);
    nombreEst.setOrigin(nombreEst.getLocalBounds().width + nombreEst.getLocalBounds().left, nombreEst.getLocalBounds().height / 2 + nombreEst.getLocalBounds().top);
    nombreEst.setPosition(size, size / 2);

    nombreSud.setCharacterSize(characterSize);
    nombreSud.setOrigin(nombreSud.getLocalBounds().width / 2 + nombreSud.getLocalBounds().left, nombreSud.getLocalBounds().height + nombreSud.getLocalBounds().top);
    nombreSud.setPosition(size / 2, size);
}

void DominoCarreTuileGUI::updateValues() {
    nombreNord.setString(dominoCarre->getValeurNordString());
    nombreOuest.setString(dominoCarre->getValeurOuestString());
    nombreEst.setString(dominoCarre->getValeurEstString());
    nombreSud.setString(dominoCarre->getValeurSudString());
}

sf::RectangleShape* DominoCarreTuileGUI::getCarre() {
    return &carre;
}

const bool DominoCarreTuileGUI::isClicked(const float x, const float y) const {
    return sf::FloatRect { getPosition(), carre.getSize() }.contains(x, y);
}

void DominoCarreTuileGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(carre, states);
    target.draw(nombreNord, states);
    target.draw(nombreOuest, states);
    target.draw(nombreEst, states);
    target.draw(nombreSud, states);
}

const std::string DominoCarreTuileGUI::to3digitString(const int n, const bool vertical) const {
    std::string text = std::to_string(n);
    if (10 > n)
        text.insert(1, "0");
    if (100 > n)
        text.insert(2, "0");
    if (vertical) {
        for (size_t i = 1; i < text.length(); i += 2)
            text.insert(i, "\n");
    }
    return text;
}