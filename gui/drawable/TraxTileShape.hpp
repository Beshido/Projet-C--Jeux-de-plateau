#ifndef _TraxTileShape
#define _TraxTileShape

#include "TileShape.hpp"
#include "../../logic/TraxTile.hpp"
#include <SFML/Graphics.hpp>

class TraxTileShape: public TileShape<TraxTile> {
    public:
        TraxTileShape(TraxTile* tile);
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        sf::Sprite sprite;
};

#endif