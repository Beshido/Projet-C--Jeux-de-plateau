#ifndef _DominoCarreTuileGUI
#define _DominoCarreTuileGUI

#include "../../Tuile.hpp"
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>

class DominoCarreTuileGUI : public sf::Drawable, public sf::Transformable {
    public:
        DominoCarreTuileGUI(Tuile<unsigned int>* dominoCarre, const sf::Font* font);
        ~DominoCarreTuileGUI();
        Tuile<unsigned int>* getTuile() const;
        void setSize(const float taille);
        sf::RectangleShape* getCarre();
        const bool isClicked(const float x, const float y) const;
        const bool isValeurNordClicked(const float x, const float y) const;
        const bool isValeurOuestClicked(const float x, const float y) const;
        const bool isValeurEstClicked(const float x, const float y) const;
        const bool isValeurSudClicked(const float x, const float y) const;
        void updateValues();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        static const unsigned int DEFAULT_SIZE;
        Tuile<unsigned int>* dominoCarre;
        sf::RectangleShape carre;
        sf::Text nombreNord;
        sf::Text nombreOuest;
        sf::Text nombreEst;
        sf::Text nombreSud;

        const std::string to3digitString(const int n, const bool vertical = false) const;
};

#endif