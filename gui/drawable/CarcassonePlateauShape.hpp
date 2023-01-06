#ifndef _CarcassonePlateauShape
#define _CarcassonePlateauShape

#include "CarcassoneTileShape.hpp"
#include "PlateauShape.hpp"
#include "PlayerShape.hpp"
#include "../../logic/Carcassone.hpp"

class CarcassonePlateauShape: public PlateauShape<Carcassone, CarcassoneTileShape, PlayerShape<Joueur<CarcassoneTile>>> {
    public:
        CarcassonePlateauShape(Carcassone* carcassone);
        void setSize(const sf::Vector2u size);
        void setSize(const unsigned int x, const unsigned int y);
        const bool fireEvent(const sf::Event::MouseButtonEvent event);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    protected:
        sf::RectangleShape getShapeFromPartisans(const Partisan partisan);
        void placePartisanIfPossible(const sf::Event::MouseButtonEvent event);
        virtual void onDrawnTileClick(const sf::Event::MouseButtonEvent event);
        virtual void onBoardTileClick(const sf::Event::MouseButtonEvent event);
        void onPassClick(const sf::Event::MouseButtonEvent event);

    private:
        sf::RectangleShape knightShape;
        sf::RectangleShape thiefShape;
        sf::RectangleShape peasantShape;
        sf::RectangleShape monkShape;
        std::vector<std::vector<std::vector<sf::RectangleShape>>> partisansShape;
        Bouton pass;
};

#endif