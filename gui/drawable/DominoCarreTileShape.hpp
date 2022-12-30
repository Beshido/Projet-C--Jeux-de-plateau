#ifndef _DominoCarreTileShape
#define _DominoCarreTileShape

#include "TileShape.hpp"
#include "../Assets.hpp"
#include "../../logic/DominoCarreTuile.hpp"
#include <SFML/Graphics.hpp>

class DominoCarreTileShape: public TileShape<DominoCarreTuile> {
    public:
        DominoCarreTileShape(DominoCarreTuile* dominoCarre);
        DominoCarreTileShape(DominoCarreTileShape* dominoCarreTileShape);
        ~DominoCarreTileShape();
        void setSize(const float size);

        virtual void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:
        static const unsigned int DEFAULT_SIZE;
        sf::Text nombreNord;
        sf::Text nombreOuest;
        sf::Text nombreEst;
        sf::Text nombreSud;
};

#endif