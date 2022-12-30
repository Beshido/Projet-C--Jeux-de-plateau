#ifndef _TraxTileShape
#define _TraxTileShape

#include "TileShape.hpp"
#include "../../logic/TraxTile.hpp"
#include <SFML/Graphics.hpp>

class TraxTileShape: public TileShape<TraxTile> {
    public:
        TraxTileShape(TraxTile* tile);
        TraxTileShape(TraxTileShape* traxTileShape);
        void flip();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        static const sf::IntRect standart;
        static const sf::IntRect flipped; 
        sf::Sprite sprite;
};

#endif