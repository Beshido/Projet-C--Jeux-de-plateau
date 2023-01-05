#include "CarcassonePlateauShape.hpp"

CarcassonePlateauShape::CarcassonePlateauShape(Carcassone* carcassone): PlateauShape<Carcassone, CarcassoneTileShape, PlayerShape<Joueur<CarcassoneTile>>> { carcassone } {}

void CarcassonePlateauShape::onDrawnTileClick(const sf::Event::MouseButtonEvent event) {
    rotateOnDrawnTileClick(event);
}

void CarcassonePlateauShape::onBoardTileClick(const sf::Event::MouseButtonEvent event) {
    placeTileIfPossible(event);
    if (event.button == sf::Mouse::Right) {
        size_t x = event.x / tileSize;
        size_t y = event.y / tileSize;
        plateau->getPlateau().at(x).at(y)->placePartisan(Partisan::Knight);
    }
}