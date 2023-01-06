#ifndef _Bouton
#define _Bouton

#include "../Assets.hpp"
#include <functional>
#include <SFML/Graphics.hpp>

class Bouton: public sf::Drawable, public sf::Transformable {
    public:
        Bouton();
        Bouton(const std::string label);
        Bouton(const std::string label, const sf::Color bgColor, sf::Color textColor);
        const sf::Vector2f getSize() const;
        void setSize(const float width, const float height);
        void setTextColor(const sf::Color color);
        void setRectangleColor(const sf::Color color);
        void setOnClickListener(const std::function<int()> onClick);
        const bool isClicked(const float x, const float y) const;
        const void fireEvent() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        static const unsigned int DEFAULT_WIDTH;
        static const unsigned int DEFAULT_HEIGHT;
        sf::RectangleShape rectangle;
        sf::Text text;
        std::function<int()> onClick;
};

#endif