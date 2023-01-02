#ifndef _CarcassoneTile
#define _CarcassoneTile

#include "Tile.hpp"

enum class CarcassoneType {
    City,
    Road,
    Field,
    Monastery,
    Grassland,
    Crossroads,
    Cloister,
    Castle,
    River,
    Count
};

class CarcassoneTuile : public Tile<CarcassoneType> {
    public:
        CarcassoneTuile();
        CarcassoneTuile(CarcassoneType type);
        CarcassoneTuile(CarcassoneType typeNord, CarcassoneType typeOuest, CarcassoneType typeEst, CarcassoneType typeSud);
    private:
        bool IsSurrounded() const;
        CarcassoneType GetType() const;
        CarcassoneType type_;  // The type of the tile
};

#endif