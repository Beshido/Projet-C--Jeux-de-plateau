#ifndef _CarcassonePlateauShape
#define _CarcassonePlateauShape

#include "CarcassoneTileShape.hpp"
#include "PlateauShape.hpp"
#include "PlayerShape.hpp"
#include "../../logic/Carcassone.hpp"

class CarcassonePlateauShape: public PlateauShape<Carcassone, CarcassoneTileShape, PlayerShape<Joueur<CarcassoneTile>>> {
    public:
        CarcassonePlateauShape(Carcassone* carcassone);
        
    protected:
        virtual void onDrawnTileClick(const sf::Event::MouseButtonEvent event);
        virtual void onBoardTileClick(const sf::Event::MouseButtonEvent event);
};

#endif