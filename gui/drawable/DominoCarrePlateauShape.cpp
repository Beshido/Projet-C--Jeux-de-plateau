#include "DominoCarrePlateauShape.hpp"

DominoCarrePlateauShape::DominoCarrePlateauShape(DominoCarre* dominoCarre): PlateauShape<DominoCarre, DominoCarreTileShape, PlayerShape<Joueur<DominoCarreTuile>>> { dominoCarre } {}

void DominoCarrePlateauShape::onDrawnTileClick(const sf::Event::MouseButtonEvent event) {
    rotateOnDrawnTileClick(event);
}