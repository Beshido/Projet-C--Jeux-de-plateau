#include "CarcassoneTile.hpp"
#include "GC.hpp"

CarcassoneTile::CarcassoneTile(const CarcassoneTileContent type, const CarcassoneType typeNord, const CarcassoneType typeOuest, const CarcassoneType typeEst, const CarcassoneType typeSud): Tile<CarcassoneType> { typeNord, typeOuest, typeEst, typeSud }, type { type } {}

CarcassoneTile* CarcassoneTile::createCarcassoneTile(const CarcassoneTileContent tile) {
    CarcassoneTile* carcassoneTile;
    switch (tile) {
        case CarcassoneTileContent::GrassCrossroadGrassCrossroad:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassCrossroadGrassCrossroad, CarcassoneType::Grass, CarcassoneType::Crossroad, CarcassoneType::Grass, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCrossroadGrassCrossroad1:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCrossroadGrassCrossroad1, CarcassoneType::City, CarcassoneType::Crossroad, CarcassoneType::Grass, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCityCrossroadCrossroad1:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCrossroadCrossroad1, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Crossroad, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCityCityCrossroad1:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCityCrossroad1, CarcassoneType::City, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCityCityGrass1:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCityGrass1, CarcassoneType::City, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::CityCityCrossroadCrossroad2:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCrossroadCrossroad2, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Crossroad, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCrossroadCrossroadCrossroad:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCrossroadCrossroadCrossroad, CarcassoneType::City, CarcassoneType::Crossroad, CarcassoneType::Crossroad, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CrossroadGrassGrassCrossroad:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CrossroadGrassGrassCrossroad, CarcassoneType::Crossroad, CarcassoneType::Grass, CarcassoneType::Grass, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::GrassCrossroadCrossroadCrossroad:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassCrossroadCrossroadCrossroad, CarcassoneType::Grass, CarcassoneType::Crossroad, CarcassoneType::Crossroad, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityGrassGrassGrass:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityGrassGrassGrass, CarcassoneType::City, CarcassoneType::Grass, CarcassoneType::Grass, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::CityGrassCityGrass:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityGrassCityGrass, CarcassoneType::City, CarcassoneType::Grass, CarcassoneType::City, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::CityCityCityGrass2:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCityGrass2, CarcassoneType::City, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::GrassGrassGrassGrassMonastery:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassGrassGrassGrassMonastery, CarcassoneType::Grass, CarcassoneType::Grass, CarcassoneType::Grass, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::GrassGrassGrassCrossroad:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassGrassGrassCrossroad, CarcassoneType::Grass, CarcassoneType::Grass, CarcassoneType::Grass, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCityGrassGrass1:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityGrassGrass1, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::GrassCityCityGrass1:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassCityCityGrass1, CarcassoneType::Grass, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::CityCrossroadCrossroadGrass:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCrossroadCrossroadGrass, CarcassoneType::City, CarcassoneType::Crossroad, CarcassoneType::Crossroad, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::CityCrossroadGrassCrossroad2:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCrossroadGrassCrossroad2, CarcassoneType::City, CarcassoneType::Crossroad, CarcassoneType::Grass, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::GrassCityCityGrass2:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassCityCityGrass2, CarcassoneType::Grass, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::CityCityCityCrossroad2:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCityCrossroad2, CarcassoneType::City, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCityCityCity:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityCityCity, CarcassoneType::City, CarcassoneType::City, CarcassoneType::City, CarcassoneType::City }; break;
        case CarcassoneTileContent::CrossroadCrossroadCrossroadCrossroad:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CrossroadCrossroadCrossroadCrossroad, CarcassoneType::Crossroad, CarcassoneType::Crossroad, CarcassoneType::Crossroad, CarcassoneType::Crossroad }; break;
        case CarcassoneTileContent::CityCityGrassGrass2:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::CityCityGrassGrass2, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass, CarcassoneType::Grass }; break;
        case CarcassoneTileContent::GrassCityCityGrass3:
            carcassoneTile = new CarcassoneTile { CarcassoneTileContent::GrassCityCityGrass3, CarcassoneType::Grass, CarcassoneType::City, CarcassoneType::City, CarcassoneType::Grass }; break;
    }
    GC::add(carcassoneTile);
    return carcassoneTile;
}

const CarcassoneTileContent CarcassoneTile::getType() const {
    return type;
}