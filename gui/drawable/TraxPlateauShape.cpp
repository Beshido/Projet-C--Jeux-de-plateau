#include "TraxPlateauShape.hpp"

TraxPlateauShape::TraxPlateauShape(Trax* trax): PlateauShape<Trax, TraxTileShape, PlayerShape<Joueur<TraxTile>>> { trax, sf::Color::Black, sf::Color::Red } {}

void TraxPlateauShape::onDrawnTileClick(const sf::Event::MouseButtonEvent event) {
    rotateOnDrawnTileClick(event);
    if (event.button == sf::Mouse::Middle) {
        std::cout << "Retournement de la tuile." << std::endl;
        drawnTile->flip();
        drawnTile->update();
    }
}

void TraxPlateauShape::onBoardTileClick(const sf::Event::MouseButtonEvent event) {
    placeTileIfPossible(event);
}