#include "DominoCarrePlateauShape.hpp"

DominoCarrePlateauShape::DominoCarrePlateauShape(DominoCarre* dominoCarre): PlateauShape<DominoCarre, DominoCarreTileShape, PlayerShape<Joueur<DominoCarreTile>>> { dominoCarre, sf::Color::Black, sf::Color::Green } {}

void DominoCarrePlateauShape::onDrawnTileClick(const sf::Event::MouseButtonEvent event) {
    rotateOnDrawnTileClick(event);
}

void DominoCarrePlateauShape::onBoardTileClick(const sf::Event::MouseButtonEvent event) {
    placeTileIfPossible(event);
}