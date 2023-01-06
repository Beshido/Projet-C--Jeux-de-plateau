#include "TraxTileShape.hpp"
#include "../Assets.hpp"

const sf::IntRect TraxTileShape::standart = sf::IntRect { 4, 5, 60, 60 }; // 150x68
const sf::IntRect TraxTileShape::flipped = sf::IntRect { 86, 5, 60, 60 };

TraxTileShape::TraxTileShape(TraxTile* tile): TileShape<TraxTile> { tile } {
    square.setTexture(&Assets::trax);
    square.setTextureRect(standart);
}

TraxTileShape::TraxTileShape(TraxTileShape* traxTileShape): TraxTileShape { traxTileShape->getTile() } {
    square.setRotation(90 * tile->getRotationFactor());
}

void TraxTileShape::flip() {
    if (tile->flip()) {
        square.setTextureRect(flipped);
    }
    else {
        square.setTextureRect(standart);
    }
    square.setRotation(0);
}

void TraxTileShape::update() {
    square.setRotation(90 * tile->getRotationFactor());
}

void TraxTileShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(square, states);
}