#ifndef _DominoCarreGUI
#define _DominoCarreGUI

#include "Bouton.hpp"
#include "DominoCarreTuileGUI.hpp"
#include "../../DominoCarre.hpp"
#include "../../Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class DominoCarreGUI : public sf::Drawable, public sf::Transformable {
    public:
        DominoCarreGUI(DominoCarre* dominoCarre, sf::Font* font);
        void setSize(const float size);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        DominoCarre* dominoCarre;
        sf::Font* font;
        vector<vector<DominoCarreTuileGUI>> dominoCarreTuilesGui;
        Bouton sacTuilesGui;
};

#endif