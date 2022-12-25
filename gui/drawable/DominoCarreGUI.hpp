#ifndef _DominoCarreGUI
#define _DominoCarreGUI

#include "Bouton.hpp"
#include "DominoCarreTuileGUI.hpp"
#include "../../DominoCarre.hpp"
#include "../../Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class DominoCarreGUI: public sf::Drawable, public sf::Transformable {
    public:
        DominoCarreGUI(DominoCarre* dominoCarre, const sf::Font* font);
        const sf::Vector2u getSize() const;
        void setSize(const unsigned int x, const unsigned int y);
        void setSize(const sf::Vector2u size);
        const bool fireEvent(const sf::Event::MouseButtonEvent event);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        DominoCarre* dominoCarre;
        const sf::Font* font;
        std::vector<std::vector<DominoCarreTuileGUI*>> dominoCarreTuilesGui;
        Bouton sacTuilesGui;
        DominoCarreTuileGUI* tuilePioche;
        sf::Vector2u size;

        const bool onSacTuileClick();
};

#endif