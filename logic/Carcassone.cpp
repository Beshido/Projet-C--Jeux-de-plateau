#include "Carcassone.hpp"
#include "CarcassoneTile.hpp"
#include <algorithm>
#include <random>
#include <vector>

const size_t Carcassone::SIZE = 9;

Carcassone::Carcassone(): Plateau<CarcassoneTile> { SIZE, 4 } {
    playedPartisans = std::vector<std::vector<std::vector<Partisan>>> { SIZE, std::vector<std::vector<Partisan>> { SIZE, std::vector<Partisan> {} } };
    
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

    srand(time(NULL));

    for (size_t i = 0; i < bag.size(); i++) {
        size_t j = rand() % bag.size();
        std::swap(bag[i], bag[j]);
    }

    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
}

const bool Carcassone::placePartisan(const size_t x, const size_t y, Partisan partisan) {
    if (!plateau.at(x).at(y)) {
        return false;
    }

    std::vector<CarcassoneType> values = std::vector<CarcassoneType> { plateau.at(x).at(y)->getValeurNord(), plateau.at(x).at(y)->getValeurOuest(), plateau.at(x).at(y)->getValeurEst(), plateau.at(x).at(y)->getValeurSud() };
    CarcassoneType value;
    switch (partisan) {
        case Partisan::Knight:
            value = CarcassoneType::Castle; 
            break;
        case Partisan::Thief:
            value = CarcassoneType::Crossroad;
            break;
        case Partisan::Peasant:
            value = CarcassoneType::Grass;
            break;
        case Partisan::Monk:
            return plateau.at(x).at(y)->getType() == CarcassoneTileContent::GrassGrassGrassGrassMonastery;
    }

    for (size_t i = 0; i < values.size(); i++) {
        if (values.at(i) == value) {
            playedPartisans.at(x).at(y).push_back(partisan);
            return true;
        }
    }
    return false;
}

const bool Carcassone::isSurrounded(const size_t x, const size_t y) const {
    const std::vector<const CarcassoneTile *> adjacentTiles = getAdjacentTiles(x, y);
    for (size_t i = 0; i < adjacentTiles.size(); i++) {
        if (!adjacentTiles.at(i)) return false;
    }
    return true;
}

const bool Carcassone::checkMonasteryRules(const size_t x, const size_t y) const {
    if (!plateau.at(x).at(y)) {
        return false;
    }

    if (plateau.at(x).at(y)->getType() != CarcassoneTileContent::GrassGrassGrassGrassMonastery) {
        return false;
    }

    std::vector<const CarcassoneTile *> adjacentTiles = getAdjacentTiles(x, y);
    if (adjacentTiles.at(0) != nullptr) return false;
    if (adjacentTiles.at(1) != nullptr) return false;
    if (adjacentTiles.at(2) != nullptr) return false;
    if (adjacentTiles.at(3) != nullptr) return false;

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