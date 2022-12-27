#ifndef _CarcassoneTuile
#define _CarcassoneTuile

#include "Tuile.hpp"

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
    Count};

class CarcassoneTuile : public Tuile<CarcassoneType> {
    public:
        CarcassoneTuile();
        CarcassoneTuile(CarcassoneType type);
        CarcassoneTuile(CarcassoneType typeNord, CarcassoneType typeOuest, CarcassoneType typeEst, CarcassoneType typeSud);
    private:
        bool IsSurrounded() const;
        CarcassoneType GetType() const;
        CarcassoneType type_;  // The type of the tile
        bool has_follower_;  // Whether the tile has a follower placed on it
        Tile* north_;  // The tile to the north of this tile
        Tile* south_;  // The tile to the south of this tile
        Tile* east_;  // The tile to the east of this tile
        Tile* west_;  // The tile to the west of this tile
};




