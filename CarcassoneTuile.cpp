#include "CarcassoneTuile.hpp"

CarcassoneTuile::CarcassoneTuile() : Tuile<CarcassoneType> {
    CarcassoneType::Grassland,
    CarcassoneType::Grassland,
    CarcassoneType::Grassland,
    CarcassoneType::Grassland
} {}
CarcassoneTuile::CarcassoneTuile(CarcassoneType type) : Tuile<CarcassoneType> {
    type,
    type,
    type,
    type
} {}
CarcassoneTuile::CarcassoneTuile(CarcassoneType typeNord, CarcassoneType typeOuest, CarcassoneType typeEst, CarcassoneType typeSud) : Tuile<CarcassoneType> {
    typeNord,
    typeOuest,
    typeEst,
    typeSud
} {}
