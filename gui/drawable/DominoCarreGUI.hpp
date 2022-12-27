#ifndef _DominoCarreGUI
#define _DominoCarreGUI

#include "Bouton.hpp"
#include "DominoCarreJoueurGUI.hpp"
#include "DominoCarreTuileGUI.hpp"
#include "../../logic/DominoCarre.hpp"
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
        sf::Vector2u size;

        std::vector<std::vector<DominoCarreTuileGUI*>> dominoCarreTuilesGui;
        std::vector<DominoCarreJoueurGUI> joueursGui;
        Bouton sacTuilesGui;
        DominoCarreTuileGUI* tuilePioche;

        const bool onSacTuileClick();
};

#endif