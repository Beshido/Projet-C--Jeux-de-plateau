#include "DominoCarreTileShape.hpp"

DominoCarreTileShape::DominoCarreTileShape(DominoCarreTile* dominoCarre): DominoCarreTileShape { dominoCarre, sf::Color::Black, sf::Color::Green, sf::Color::Green, sf::Color::Green, sf::Color::Green, sf::Color::Green } {}

DominoCarreTileShape::DominoCarreTileShape(DominoCarreTile* dominoCarre, sf::Color bg, sf::Color outline, sf::Color ColorN, sf::Color ColorO, sf::Color ColorE, sf::Color ColorS): TileShape<DominoCarreTile> { dominoCarre } {
    square.setFillColor(bg);
    square.setOutlineColor(outline);
    square.setOutlineThickness(1);

    nombreNord.setFont(Assets::font);
    nombreNord.setFillColor(ColorN);

    nombreOuest.setFont(Assets::font);
    nombreOuest.setFillColor(ColorO);
    nombreOuest.setLineSpacing(0.5);
    
    nombreEst.setFont(Assets::font);
    nombreEst.setFillColor(ColorE);
    nombreEst.setLineSpacing(0.5);
    
    nombreSud.setFont(Assets::font);
    nombreSud.setFillColor(ColorS);

    update();
}

DominoCarreTileShape::DominoCarreTileShape(DominoCarreTileShape* dominoCarreTileShape): DominoCarreTileShape { dominoCarreTileShape->getTile() } {}

DominoCarreTileShape::~DominoCarreTileShape() {
    std::cout << "Destruction de DominoCarreTileShape." << std::endl;
}

void DominoCarreTileShape::setSize(const float size) {
    TileShape<DominoCarreTile>::setSize(size);

    const unsigned int characterSize = size / 4;

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

void DominoCarreTileShape::update() {
    nombreNord.setString(tile->getValeurNordString());
    nombreOuest.setString(tile->getValeurOuestString());
    nombreEst.setString(tile->getValeurEstString());
    nombreSud.setString(tile->getValeurSudString());
}

void DominoCarreTileShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(square, states);
    target.draw(nombreNord, states);
    target.draw(nombreOuest, states);
    target.draw(nombreEst, states);
    target.draw(nombreSud, states);
}