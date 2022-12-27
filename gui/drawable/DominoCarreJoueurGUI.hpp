#ifndef _DominoCarreJoueurGUI
#define _DominoCarreJoueurGUI

#include "../../logic/DominoCarreTuile.hpp"
#include "../../logic/Joueur.hpp"
#include <SFML/Graphics.hpp>

class DominoCarreJoueurGUI: public sf::Drawable, public sf::Transformable {
    public:
        DominoCarreJoueurGUI(Joueur<DominoCarreTuile>* joueur, const sf::Font* font);
        void updateValues();
        void setSize(const float x, const float y);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    private:
        Joueur<DominoCarreTuile>* joueur;
        const sf::Font* font;

        sf::RectangleShape rectangle;
        sf::Text name;
        sf::Text score;
};

#endif