#ifndef _DominoCarreJoueurShape
#define _DominoCarreJoueurShape

#include "PlayerShape.hpp"
#include "../Assets.hpp"
#include "../../logic/DominoCarreTuile.hpp"
#include "../../logic/Joueur.hpp"
#include <SFML/Graphics.hpp>

class DominoCarreJoueurShape: public PlayerShape<Joueur<DominoCarreTuile>>  {
    public:
        DominoCarreJoueurShape(Joueur<DominoCarreTuile>* joueur);
        void setSize(const float x, const float y);
        virtual void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    private:
        sf::Text score;
};

#endif