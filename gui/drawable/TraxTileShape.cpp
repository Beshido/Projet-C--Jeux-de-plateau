#include "TraxTileShape.hpp"
#include "../Assets.hpp"

TraxTileShape::TraxTileShape(TraxTile* tile): TileShape<TraxTile> { tile } {
    square.setTexture(&Assets::trax);
}

void TraxTileShape::update() {
    square.setRotation(90 * tile->getRotationFactor());
}

void TraxTileShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(square, states);
}
