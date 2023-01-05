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

void CarcassonePlateauShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    PlateauShape::draw(target, states);
    for (size_t x = 0; x < plateau->getWidth(); x++) {
        for (size_t y = 0; y < plateau->getHeight(); y++) {
            if (tilesShape[x][y] && tilesShape.at(x).at(y)) {
                std::cout << x << ", " << y << std::endl;
                sf::RectangleShape rect { sf::Vector2f{ 20, 20 } };
                rect.setFillColor(sf::Color::Red);
                rect.setPosition(x * tileSize, y * tileSize);
                target.draw(rect, states);
            }
        }
    }
}