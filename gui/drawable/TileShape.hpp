#ifndef _TileShape
#define _TileShape

#include "Bouton.hpp"
#include <SFML/Graphics.hpp>

template <typename P> class TileShape: public sf::Drawable, public sf::Transformable {
    public:
        TileShape(P* tile): tile { tile } {
            square.setSize( sf::Vector2f { DEFAULT_SIZE, DEFAULT_SIZE });
        }

        const bool isClicked(const float x, const float y) const { return sf::FloatRect { getPosition(), getSize() }.contains(x, y); }
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
