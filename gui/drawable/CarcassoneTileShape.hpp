#ifndef _CarcassoneTileShape
#define _CarcassoneTileShape

#include "TileShape.hpp"
#include "../Assets.hpp"
#include "../../logic/CarcassoneTile.hpp"
#include <SFML/Graphics.hpp>

class CarcassoneTileShape: public TileShape<CarcassoneTile> {
    public:
        CarcassoneTileShape(CarcassoneTile* tile);
        CarcassoneTileShape(CarcassoneTileShape* TileShape);
        ~CarcassoneTileShape();

        virtual void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:
        sf::IntRect rect;
        sf::Sprite sprite;
};

#endif