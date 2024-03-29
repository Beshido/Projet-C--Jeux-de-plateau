#ifndef _DominoCarrePlateauShape
#define _DominoCarrePlateauShape

#include "DominoCarreTileShape.hpp"
#include "PlateauShape.hpp"
#include "PlayerShape.hpp"
#include "../../logic/DominoCarre.hpp"

class DominoCarrePlateauShape: public PlateauShape<DominoCarre, DominoCarreTileShape, PlayerShape<Joueur<DominoCarreTile>>> {
    public:
        DominoCarrePlateauShape(DominoCarre* dominoCarre);

    protected:
        virtual void onDrawnTileClick(const sf::Event::MouseButtonEvent event);
        virtual void onBoardTileClick(const sf::Event::MouseButtonEvent event);

};

#endif