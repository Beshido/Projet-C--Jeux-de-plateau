#ifndef _Bouton
#define _Bouton

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Bouton: public sf::Drawable, public sf::Transformable {
    public:
        Bouton(const std::string label, const sf::Font* font);
        const sf::Vector2f getSize() const;
        void setSize(const float width, const float height);
        void setTextColor(const sf::Color color);
        void setRectangleColor(const sf::Color color);
        bool isClicked(const sf::Event event);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        static const unsigned int DEFAULT_WIDTH;
        static const unsigned int DEFAULT_HEIGHT; 
        sf::RectangleShape rectangle;
        sf::Text texte;
};

#endif