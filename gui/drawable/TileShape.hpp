#ifndef _TileShape
#define _TileShape

#include <iostream>
#include "Bouton.hpp"
#include <SFML/Graphics.hpp>

template <typename P> class TileShape: public sf::Drawable, public sf::Transformable {
    public:
        TileShape(P* tile): tile { tile } {
            square.setSize( sf::Vector2f { DEFAULT_SIZE, DEFAULT_SIZE });
        }

        TileShape(TileShape<P>* tileShape): TileShape { tileShape->getTile() } {
            setSize(tileShape->getSize().x);
        }
        
        ~TileShape() {
            /* delete tile; */
            std::cout << "TileShape supprimé." << std::endl;    
        }

        const bool isClicked(const float x, const float y) const { return sf::FloatRect { getPosition(), getSize() }.contains(x, y); }
        
        void centerOrigin() {
            const float originX = square.getLocalBounds().width / 2 + square.getLocalBounds().left;
            const float originY = square.getLocalBounds().height / 2 + square.getLocalBounds().top;
            square.setOrigin(originX, originY);
            square.move(originX, originY);
        }
        
        void setSize(const float size) { square.setSize(sf::Vector2f { size, size }); }
        const sf::Vector2f getSize() const { return square.getSize(); }
        P* getTile() const { return tile; }
        virtual void update() = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    protected:
        P* tile;

        sf::RectangleShape square;

    private:
        static const unsigned long DEFAULT_SIZE = 300;
};

#endif
