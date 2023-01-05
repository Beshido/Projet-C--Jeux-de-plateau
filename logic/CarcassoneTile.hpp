#ifndef _CarcassoneTile
#define _CarcassoneTile

#include "Tile.hpp"

enum class CarcassoneType {
    City,
    Road,
    Grass,
    Monastery,
    Grassland,
    Crossroad,
    Cloister,
    Castle,
    River,
    Count
};

enum class CarcassoneTileContent {
    GrassCrossroadGrassCrossroad, // 9
    CityCrossroadGrassCrossroad1, // 3
    CityCityCrossroadCrossroad1, // 2
    CityCityCityCrossroad1, // 1
    CityCityCityGrass1, // 1
    CityCityCrossroadCrossroad2, // 3
    CityCrossroadCrossroadCrossroad, // 3
    CrossroadGrassGrassCrossroad, // 8
    GrassCrossroadCrossroadCrossroad, // 4
    
    CityGrassGrassGrass, // 5
    CityGrassCityGrass, // 2
    CityCityCityGrass2, // 3
    GrassGrassGrassGrassMonastery, // 4
    GrassGrassGrassCrossroad, // 2
    CityCityGrassGrass1, // 3
    GrassCityCityGrass1, // 2
    CityCrossroadCrossroadGrass, // 4
    CityCrossroadGrassCrossroad2, // 3
    
    GrassCityCityGrass2, // 1
    CityCityCityCrossroad2, // 2
    CityCityCityCity, // 1
    CrossroadCrossroadCrossroadCrossroad, // 1
    CityCityGrassGrass2, // 2
    GrassCityCityGrass3 // 3
};

enum class Partisan {
    Knight,
    Thief,
    Peasant,
    Monk
};

class CarcassoneTile: public Tile<CarcassoneType> {
    public:
        CarcassoneTile(const CarcassoneTileContent type, const CarcassoneType typeNord, const CarcassoneType typeOuest, const CarcassoneType typeEst, const CarcassoneType typeSud);
        static CarcassoneTile* createCarcassoneTile(const CarcassoneTileContent tile);

        const bool placePartisan(Partisan partisan);
        const bool hasPartisan(Partisan partisan);
        const CarcassoneTileContent getType() const;
        
    private:
        const CarcassoneTileContent type;  // The type of the tile
        Partisan* partisan;
};

#endif