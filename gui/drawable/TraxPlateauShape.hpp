#ifndef _TraxPlateauShape
#define _TraxPlateauShape

#include "PlateauShape.hpp"
#include "PlayerShape.hpp"
#include "TraxTileShape.hpp"
#include "../../logic/Trax.hpp"

class TraxPlateauShape: public PlateauShape<Trax, TraxTileShape, PlayerShape<Joueur<TraxTile>>> {
    public:
        TraxPlateauShape(Trax* trax);

    protected:
        virtual void onDrawnTileClick(const sf::Event::MouseButtonEvent event);

};

#endif