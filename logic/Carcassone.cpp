#include "Carcassone.hpp"
#include "CarcassoneTile.hpp"
#include <random>
#include <vector>

const size_t Carcassone::SIZE = 9;

Carcassone::Carcassone(): Plateau<CarcassoneTile> { SIZE, 4 } {
    for (size_t i = 0; i < 9; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassCrossroadGrassCrossroad));
    for (size_t i = 0; i < 3; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCrossroadGrassCrossroad1));
    for (size_t i = 0; i < 2; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityCrossroadCrossroad1));
    bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityCityCrossroad1));
    bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityCityGrass1));
    for (size_t i = 0; i < 8; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CrossroadGrassGrassCrossroad));
    for (size_t i = 0; i < 4; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassCrossroadCrossroadCrossroad));

    for (size_t i = 0; i < 5; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityGrassGrassGrass));
    for (size_t i = 0; i < 2; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityGrassCityGrass));
    for (size_t i = 0; i < 3; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityCityGrass2));
    for (size_t i = 0; i < 4; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassGrassGrassGrassMonastery));
    for (size_t i = 0; i < 2; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassGrassGrassCrossroad));
    for (size_t i = 0; i < 3; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityGrassGrass1));
    for (size_t i = 0; i < 2; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassCityCityGrass1));
    for (size_t i = 0; i < 4; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCrossroadCrossroadGrass));
    for (size_t i = 0; i < 3; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCrossroadGrassCrossroad2));

    bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassCityCityGrass2));
    for (size_t i = 0; i < 2; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityCityCrossroad2));
    bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityCityCity));
    bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CrossroadCrossroadCrossroadCrossroad));
    for (size_t i = 0; i < 2; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::CityCityGrassGrass2));
    for (size_t i = 0; i < 3; i++) bag.push_back(CarcassoneTile::createCarcassoneTile(CarcassoneTileContent::GrassCityCityGrass3));

    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
}

const bool Carcassone::isSurrounded(const size_t x, const size_t y) const {
    const std::vector<const CarcassoneTile *> adjacentTiles = getAdjacentTiles(x, y);
    for (size_t i = 0; i < adjacentTiles.size(); i++) {
        if (!adjacentTiles.at(i)) return false;
    }
    return true;
}

const bool Carcassone::isFinished() const {
    return bag.size() == 0;
}

const bool Carcassone::isNextPlayerTurn() const {
    return true;
}

const bool Carcassone::isPlayable(const CarcassoneTile* tuile, const size_t x, const size_t y) const {
    return isAdjacentValuesEqual(tuile, x, y);
}

void Carcassone::updateScore(const size_t x, const size_t y) {

}