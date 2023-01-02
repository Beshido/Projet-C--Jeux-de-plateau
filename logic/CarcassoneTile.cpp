#include "CarcassoneTile.hpp"

CarcassoneTuile::CarcassoneTuile() : Tuile<CarcassoneType> { CarcassoneType::Grassland, CarcassoneType::Grassland, CarcassoneType::Grassland, CarcassoneType::Grassland } {}
CarcassoneTuile::CarcassoneTuile(CarcassoneType type) : Tuile<CarcassoneType> { type, type, type, type } {}
CarcassoneTuile::CarcassoneTuile(CarcassoneType typeNord, CarcassoneType typeOuest, CarcassoneType typeEst, CarcassoneType typeSud) : Tuile<CarcassoneType> { typeNord, typeOuest, typeEst, typeSud } {}

bool IsSurrounded() const {
    // Check if there are tiles in all four directions
    return north_ != nullptr && south_ != nullptr &&
           east_ != nullptr && west_ != nullptr;
  }
TileType GetType() const {
    return type_;
  }
bool HasFollower() const {
    return has_follower_;
  }
  // Returns true if the tile is part of a completed area, false otherwise
bool IsCompleted() const {
    // Check if the tile is a city or road and if it is fully surrounded by other tiles
    return (type_ == CarcassoneType::City || type_ == CarcassoneTuile::Road) &&
           IsSurrounded();
  }