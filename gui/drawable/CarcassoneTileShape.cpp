#include "CarcassoneTileShape.hpp"

CarcassoneTileShape::CarcassoneTileShape(CarcassoneTile* tile): TileShape<CarcassoneTile> { tile } {
    square.setTexture(&Assets::carcassone);
    int x = 0, y = 0, width = 234, height = 234, offsetX = 35, offsetY = 128;
    switch (tile->getType()) {
        case CarcassoneTileContent::GrassCrossroadGrassCrossroad:
            break;
        case CarcassoneTileContent::CityCrossroadGrassCrossroad1:
            x = (width + offsetX) * 1; break;
        case CarcassoneTileContent::CityCityCrossroadCrossroad1:
            x = (width + offsetX) * 2; break;
        case CarcassoneTileContent::CityCityCityCrossroad1:
            x = (width + offsetX) * 3; break;
        case CarcassoneTileContent::CityCityCityGrass1:
            x = (width + offsetX) * 4; break;
        case CarcassoneTileContent::CityCityCrossroadCrossroad2:
            x = (width + offsetX) * 5; break;
        case CarcassoneTileContent::CityCrossroadCrossroadCrossroad:
            x = (width + offsetX) * 6; break;
        case CarcassoneTileContent::CrossroadGrassGrassCrossroad:
            x = (width + offsetX) * 7; break;
        case CarcassoneTileContent::GrassCrossroadCrossroadCrossroad:
            x = (width + offsetX) * 8; break;
        case CarcassoneTileContent::CityGrassGrassGrass:
            x = (width + offsetX) * 0; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::CityGrassCityGrass:
            x = (width + offsetX) * 1; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::CityCityCityGrass2:
            x = (width + offsetX) * 2; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::GrassGrassGrassGrassMonastery:
            x = (width + offsetX) * 3; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::GrassGrassGrassCrossroad:
            x = (width + offsetX) * 4; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::CityCityGrassGrass1:
            x = (width + offsetX) * 5; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::GrassCityCityGrass1:
            x = (width + offsetX) * 6; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::CityCrossroadCrossroadGrass:
            x = (width + offsetX) * 7; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::CityCrossroadGrassCrossroad2:
            x = (width + offsetX) * 8; y = (height + offsetY) * 1; break;
        case CarcassoneTileContent::GrassCityCityGrass2:
            x = (width + offsetX) * 1 + width / 2; y = (height + offsetY) * 2; break;
        case CarcassoneTileContent::CityCityCityCrossroad2:
            x = (width + offsetX) * 2 + width / 2; y = (height + offsetY) * 2; break;
        case CarcassoneTileContent::CityCityCityCity:
            x = (width + offsetX) * 3 + width / 2; y = (height + offsetY) * 2; break;
        case CarcassoneTileContent::CrossroadCrossroadCrossroadCrossroad:
            x = (width + offsetX) * 4 + width / 2; y = (height + offsetY) * 2; break;
        case CarcassoneTileContent::CityCityGrassGrass2:
            x = (width + offsetX) * 5 + width / 2; y = (height + offsetY) * 2; break;
        case CarcassoneTileContent::GrassCityCityGrass3:
            x = (width + offsetX) * 6 + width / 2; y = (height + offsetY) * 2; break;
            
    }
    square.setTextureRect(sf::IntRect { x, y, width, height });
}

CarcassoneTileShape::CarcassoneTileShape(CarcassoneTileShape* tileShape): CarcassoneTileShape { tileShape->getTile() } {
    square.setRotation(90 * tile->getRotationFactor());
}

CarcassoneTileShape::~CarcassoneTileShape() {
    std::cout << "Destruction de CarcassoneTileShape." << std::endl;
}

void CarcassoneTileShape::update() {
    square.setRotation(90 * tile->getRotationFactor());
}

void CarcassoneTileShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(square, states);
}