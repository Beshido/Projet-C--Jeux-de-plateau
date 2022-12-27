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
};




